/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** GUI
*/

#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>
#include "GUI.hh"

RayTracer::GUI::GUI(std::vector<RayTracer::Primitives::Sphere> spheres, RayTracer::Camera &camera, sf::Image& pixelView, std::string windowTitle, std::size_t nbThreads):
    _window(sf::VideoMode(pixelView.getSize().x, pixelView.getSize().y), windowTitle), _pixelView(pixelView),
    _texture(std::make_unique<sf::Texture>()), _sprite(std::make_unique<sf::Sprite>()), _spheres(spheres), _cam(camera)
{
    std::size_t maxThreads = std::thread::hardware_concurrency();
    double yAxis = _cam.getScreen().getBottomSide().length();

    if (maxThreads == 0) {
        maxThreads = 1;
    }
    _camChanged = true;
    for (std::size_t i = 0; i < std::min(maxThreads, nbThreads); i++) {
        _renderComplete.push_back(true);
        _threads.push_back(std::thread(&GUI::_refreshRender, this, i * (yAxis / nbThreads), (yAxis / nbThreads), i));
    }
}

RayTracer::GUI::~GUI()
{
}

void RayTracer::GUI::render(void)
{
    bool refresh = true;
    if (!_window.isOpen()) {
        return;
    }
    _handleEvents();

    for (auto finish : _renderComplete) {
        if (!finish) {
            refresh = false;
            break;
        }
    }
    if (refresh) {
        _texture->loadFromImage(_pixelView);
        _sprite->setTexture(*_texture);
    }
    _window.clear();
    _window.draw(*_sprite);
    _window.display();
}

bool RayTracer::GUI::isOpen(void)
{
    return _window.isOpen();
}

void RayTracer::GUI::_handleEvents(void)
{
    sf::Event event;

    _camChanged = false;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        }
        if (event.type != sf::Event::KeyPressed || !_renderIsFinished()) {
            continue;
        }
        if (event.key.code == sf::Keyboard::Z) {
            _cam.moveCamera(Math::Vector3D(0, 0, -10));
        } else if (event.key.code == sf::Keyboard::Q) {
            _cam.moveCamera(Math::Vector3D(-10, 0, 0));
        } else if (event.key.code == sf::Keyboard::D) {
            _cam.moveCamera(Math::Vector3D(10, 0, 0));
        } else if (event.key.code == sf::Keyboard::S) {
            _cam.moveCamera(Math::Vector3D(0, 0, 10));
        } else if (event.key.code == sf::Keyboard::Space) {
            _cam.moveCamera(Math::Vector3D(0, -10, 0));
        } else if (event.key.code == sf::Keyboard::LShift) {
            _cam.moveCamera(Math::Vector3D(0, 10, 0));
        } else {
            continue;
        }
        {
            std::lock_guard<std::mutex> lk(_camMutex);
            _camChanged = true;
        }
        _camCv.notify_all();
    }
}

void RayTracer::GUI::_refreshRender(std::size_t yStart, std::size_t nbStep, std::size_t threadIndex)
{
    std::unique_lock<std::mutex> lk(_camMutex);
    while (_window.isOpen()) {
        _camCv.wait(lk, [&]{ return _camChanged.load(); });

        double lightIntensity = 0.9;
        double ambientFactor = 0.2;
        double diffuseFactor = 0;
        double light = (ambientFactor + diffuseFactor * (1 - ambientFactor)) * lightIntensity;
        double xAxis = _cam.getScreen().getLeftSide().length();
        double yAxis = _cam.getScreen().getBottomSide().length();
        Math::Vector3D lightDir(1, 1, 1);
        RayTracer::Ray ray;
        std::vector<std::pair<RayTracer::Primitives::Sphere, double>> closest;

        _renderComplete[threadIndex] = false;
        lk.unlock();
        lightDir.normalize();

        for (double y = yStart; y < yStart + nbStep; y++) {
            for (double x = 0; x < xAxis; x++) {
                double u = x / xAxis;
                double v = y / yAxis;
                ray = _cam.ray(u, v);
                closest.clear();

                for (auto s : _spheres) {
                    std::vector<double> t = s.hits(ray);
                    if (t.empty()) {
                        continue;
                    }
                    if (closest.size() == 0) {
                        closest.push_back({s, t[1]});
                    } else if (t[1] < closest[0].second) {
                        closest.clear();
                        closest.push_back({s, t[1]});
                    }
                }

                if (closest.empty()) {
                    _pixelView.setPixel(x, y, sf::Color::Transparent);
                    continue;
                }

                Math::Vector3D hitPosition = (ray.getDirection() * closest[0].second) + ray.getOrigin();
                Math::Vector3D normal = hitPosition - closest[0].first.center;
                normal.normalize();
                Math::Point3D shadowOrigin = hitPosition + normal * 1e-4;
                RayTracer::Ray shadowRay(shadowOrigin, lightDir);
                sf::Color color = sf::Color::Red;
                bool inShadow = false;

                for (auto &s : _spheres) {
                    if (&s == &closest[0].first) {
                        continue;
                    }

                    std::vector<double> t = s.hits(shadowRay);
                    for (double tValue : t) {
                        if (tValue > 1e-4) {
                            inShadow = true;
                            break;
                        }
                    }
                    if (inShadow) {
                        break;
                    }
                }

                if (inShadow) {
                    diffuseFactor = 0.0;
                } else {
                    diffuseFactor = std::max(normal.dot(lightDir), 0.0);
                }
                light = (ambientFactor + diffuseFactor * (1 - ambientFactor)) * lightIntensity;
                color.r = std::min(static_cast<int>(color.r * light), 255);
                color.g = std::min(static_cast<int>(color.g * light), 255);
                color.b = std::min(static_cast<int>(color.b * light), 255);
                {
                    std::lock_guard<std::mutex> lock(_pixelMutex);
                    _pixelView.setPixel(static_cast<unsigned int>(x),
                        static_cast<unsigned int>(y),
                        color);
                }
            }
        }
        _renderComplete[threadIndex] = true;
        lk.lock();
    }
}

bool RayTracer::GUI::_renderIsFinished(void)
{
    for (auto finish : _renderComplete) {
        if (!finish) {
            return false;
        }
    }
    return true;
}
