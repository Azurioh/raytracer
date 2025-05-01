/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scene
*/

#include <iostream>
#include <fstream>
#include "Scene.hh"
#include "RayTracer/Primitives/Flat/Sphere/Sphere.hh"
#include "RayTracer/Factories/Primitives/FlatFactory/FlatFactory.hh"

RayTracer::Scene::Scene(): _camera(std::make_unique<RayTracer::Camera>()), _ambientFactor(0.2), _diffuseFactor(0)
{
    Factories::Primitive::FlatFactory factory;

    _primitives.push_back(factory.createSphere(Math::Point3D(100, 100, 100), 20));
    _primitives.push_back(factory.createSphere(Math::Point3D(0, 0, 0), 100));
    _lights.push_back(std::unique_ptr<RayTracer::Light>(new RayTracer::Light(Math::Vector3D(1, 1, 1))));

    makeRender();
    exportToOutputFile();
}

RayTracer::Scene::~Scene()
{
}

std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t>>> RayTracer::Scene::getPixels(void) const
{
	return _pixels;
}

void RayTracer::Scene::setPixels(std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t>>> pixels)
{
	_pixels = pixels;
}

void RayTracer::Scene::moveCamera(CameraMovement movement)
{
    Math::Point3D pos = _camera->getOrigin();
    Math::Point3D screenPos = _camera->getScreen().getOrigin();

    switch (movement) {
        case FRONT:
            _camera->moveCamera(Math::Vector3D(0, 0, -100));
            break;
        case BACK:
            _camera->moveCamera(Math::Vector3D(0, 0, 100));
            break;
        case LEFT:
            _camera->moveCamera(Math::Vector3D(-100, 0, 0));
            break;
        case RIGHT:
            _camera->moveCamera(Math::Vector3D(100, 0, 0));
            break;
        default:
            break;
    }
    _camera->setOrigin(pos);
    _camera->getScreen().setOrigin(screenPos);
}

void RayTracer::Scene::makeRender(void)
{
    unsigned int nbThreads = std::max(std::thread::hardware_concurrency(), static_cast<unsigned int>(1));
    std::size_t nbLines = _camera->getScreen().getLeftSide().getY();
    std::size_t nbCols = _camera->getScreen().getBottomSide().getX();
    std::vector<std::thread> threads;
    unsigned int i = 0;

    _pixels.resize(nbLines);
    for (double i = 0; i < nbLines; i++) {
        _pixels[i].resize(nbCols);
    }

    for (i = 0; i < nbThreads - 1; i++) {
        threads.push_back(std::thread(&RayTracer::Scene::_renderThreading, this, i * (nbLines / nbThreads), (nbLines / nbThreads)));
    }
    if (nbLines % nbThreads != 0) {
        threads.push_back(std::thread(&RayTracer::Scene::_renderThreading, this, i * (nbLines / nbThreads), (nbLines / nbThreads) + (nbLines % nbThreads)));
    } else {
        threads.push_back(std::thread(&RayTracer::Scene::_renderThreading, this, i * (nbLines / nbThreads), (nbLines / nbThreads)));
    }
    for (std::size_t i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
}

void RayTracer::Scene::exportToOutputFile(void)
{
    std::ofstream file("output.ppm");

    if (!file.is_open()) {
        std::cerr << "Can't write in the output.ppm file" << std::endl;
        return;
    }
    file << "P3\n";
    file << _pixels[0].size() << " " << _pixels.size() << "\n";
    file << "255\n";
    for (auto lines : _pixels) {
        for (auto pixel : lines) {
            file << static_cast<int>(std::get<0>(pixel)) << " "
                 << static_cast<int>(std::get<1>(pixel)) << " "
                 << static_cast<int>(std::get<2>(pixel)) << "\n";
        }
    }
    file.close();
    std::cout << "Image exported in the output.ppm file" << std::endl;
}

std::pair<RayTracer::IPrimitive *, double> RayTracer::Scene::_getClosestPrimitive(RayTracer::Ray ray)
{
    std::pair<RayTracer::IPrimitive *, double> closest = {nullptr, 0};
    std::vector<double> tValues;

    for (auto it = _primitives.begin(); it != _primitives.end(); it++) {
        tValues = (*it)->hits(ray);
        if (tValues.empty()) {
            continue;
        }
        if (closest.first == nullptr || tValues[1] < closest.second) {
            closest = {it->get(), tValues[1]};
        }
    }
    return closest;
}

std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> RayTracer::Scene::_getColor(RayTracer::IPrimitive *primitive, double determinant, RayTracer::Ray ray)
{
    Math::Vector3D hitPosition = (ray.getDirection() * determinant) + ray.getOrigin();
    Math::Vector3D normal = hitPosition - primitive->getCenter();
    Math::Vector3D lightDirection;
    Math::Point3D shadowOrigin;
    RayTracer::Ray shadowRay;
    double light;
    double diffuseFactor = _diffuseFactor;
    bool inShadow;

    normal.normalize();
    shadowOrigin = hitPosition + normal * 1e-4;
    lightDirection = _lights[0]->getDirection();
    shadowRay = RayTracer::Ray(shadowOrigin, lightDirection);
    inShadow = _isInShadow(primitive, shadowRay);

    if (inShadow) {
        diffuseFactor = 0.0;
    } else {
        diffuseFactor = std::max(normal.dot(lightDirection), 0.0);
    }
    light = (_ambientFactor + diffuseFactor * (1 - _ambientFactor)) * _lights[0]->getIntensity();
    return _applyLightOnPixel(primitive, light);
}

bool RayTracer::Scene::_isInShadow(RayTracer::IPrimitive *primitive, RayTracer::Ray shadowRay)
{
    std::vector<double> tValues;

    for (auto it = _primitives.begin(); it != _primitives.end(); it++) {
        if (it->get() == primitive) {
            continue;
        }
        tValues = (*it)->hits(shadowRay);
        for (double t : tValues) {
            if (t > 1e-4) {
                return true;
            }
        }
    }
    return false;
}

std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> RayTracer::Scene::_applyLightOnPixel(RayTracer::IPrimitive *primitive, double light)
{
    std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> color = primitive->getColor();

    color = {
        std::min(static_cast<int>(std::get<0>(color) * light), 255),
        std::min(static_cast<int>(std::get<1>(color) * light), 255),
        std::min(static_cast<int>(std::get<2>(color) * light), 255),
    };
    return color;
}

void RayTracer::Scene::_renderThreading(std::size_t yStart, std::size_t nbStep)
{
    std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> color;
    RayTracer::Ray ray;

    double u;
    double v;
    double yAxis = _camera->getScreen().getLeftSide().getY();
    double xAxis = _camera->getScreen().getBottomSide().getX();

    for (double y = yStart; y < yStart + nbStep && y < yAxis; y++) {
        for (double x = 0; x < xAxis; x++) {
            u = x / xAxis;
            v = y / yAxis;
            ray = _camera->ray(u, v);

            std::pair<RayTracer::IPrimitive *, double> closest = _getClosestPrimitive(ray);
            if (closest.first == nullptr) {
                _pixels[y][x] = {0, 0, 0};
                continue;
            }

            color = _getColor(closest.first, closest.second, ray);
            _pixels[y][x] = color;
        }
    }
    return;
}
