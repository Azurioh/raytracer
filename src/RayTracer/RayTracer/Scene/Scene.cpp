/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scene
*/

#include "RayTracer/Builders/Director/Director.hpp"
#include "RayTracer/Builders/Plane/PlaneBuilder.hh"
#include "RayTracer/Builders/Sphere/SphereBuilder.hh"
#include "Math/Vector3D/Vector3D.hh"
#include "Scene.hh"

#include <iostream>
#include <fstream>

RayTracer::Scene::Scene(): _camera(std::make_unique<RayTracer::Camera>()), _ambientFactor(0.2), _diffuseFactor(1.0)
{
    Builders::Director director;
    Builders::SphereBuilder sphereBuilder;
    Builders::PlaneBuilder planeBuilder;

    director.makePrimitive<Primitives::Sphere>(sphereBuilder,
        Math::Point3D(0, 0, 0),
        {255, 0, 0, 255},
        {false, 0.0},
        {false, 0.0},
        Math::Vector3D(0, 0, 0),
        100.0
    );
    _primitives.push_back(std::move(sphereBuilder.getPrimitive()));
    director.makePrimitive<Primitives::Sphere>(sphereBuilder,
        Math::Point3D(-150, 50, -100),
        {0, 255, 0, 255},
        {false, 0.0},
        {false, 0.0},
        Math::Vector3D(0, 0, 0),
        50.0
    );
    _primitives.push_back(std::move(sphereBuilder.getPrimitive()));
    director.makePrimitive<Primitives::Sphere>(sphereBuilder,
        Math::Point3D(150, 50, -100),
        {0, 0, 255, 255},
        {false, 0.0},
        {false, 0.0},
        Math::Vector3D(0, 0, 0),
        50.0
    );
    _primitives.push_back(std::move(sphereBuilder.getPrimitive()));
    director.makePrimitive<Primitives::Plane>(planeBuilder,
        Math::Point3D(0, 100, 0),
        {240, 240, 240, 255},
        {true, 0.5},
        {false, 0.0},
        Math::Vector3D(0, 0, 0),
        Math::Vector3D(0, -1, 0)
    );
    _primitives.push_back(std::move(planeBuilder.getPrimitive()));

    Math::Vector3D lightDir(-1, 1, -1);
    lightDir.normalize();
    _lights.push_back(std::unique_ptr<RayTracer::Light>(new RayTracer::Light(lightDir, 1.0)));

    _primitives[0]->setColor({255, 0, 0, 255});
    _primitives[1]->setColor({0, 255, 0, 255});
    _primitives[2]->setColor({0, 0, 255, 255});

    _primitives[3]->setColor({240, 240, 240, 255});
    _primitives[3]->setHavingReflection(true);
    _primitives[3]->setReflectionIntensity(0.5);

    makeRender();
}

std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> RayTracer::Scene::getPixels(void) const
{
	return _pixels;
}

void RayTracer::Scene::setPixels(std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> pixels)
{
	_pixels = pixels;
}

void RayTracer::Scene::moveCamera(CameraMovement movement)
{
    Screen screen = _camera->getScreen();
    Math::Point3D newOrigin = screen.getOrigin();
    Math::Vector3D newLeft = screen.getLeftSide();
    Math::Vector3D newBottom = screen.getBottomSide();

    switch (movement) {
        case FRONT:
            _camera->moveCamera({0,0,-100});
            newOrigin += Math::Vector3D(0,0,-100);
            break;
        case BACK:
            _camera->moveCamera({0,0,100});
            newOrigin += Math::Vector3D(0,0,100);
            break;
        case LEFT:
            _camera->moveCamera({-100,0,0});
            newOrigin += Math::Vector3D(-100,0,0);
            break;
        case RIGHT:
            _camera->moveCamera({100,0,0});
            newOrigin += Math::Vector3D(100,0,0);
            break;
        case UP_ANGLE:
            newLeft.rotateX(-1);
            newBottom.rotateX(-1);
            {
                Math::Vector3D tmp = screen.getOrigin() - _camera->getOrigin();
                tmp.rotateX(-1);
                newOrigin = tmp + _camera->getOrigin();
            }
            break;
        case DOWN_ANGLE:
            newLeft.rotateX(1);
            newBottom.rotateX(1);
            {
                Math::Vector3D tmp = screen.getOrigin() - _camera->getOrigin();
                tmp.rotateX(1);
                newOrigin = tmp + _camera->getOrigin();
            }
            break;
        case LEFT_ANGLE:
            newLeft.rotateY(1);
            newBottom.rotateY(1);
            {
                Math::Vector3D tmp = screen.getOrigin() - _camera->getOrigin();
                tmp.rotateY(1);
                newOrigin = tmp + _camera->getOrigin();
            }
            break;
        case RIGHT_ANGLE:
            newLeft.rotateY(-1);
            newBottom.rotateY(-1);
            {
                Math::Vector3D tmp = screen.getOrigin() - _camera->getOrigin();
                tmp.rotateY(-1);
                newOrigin = tmp + _camera->getOrigin();
            }
        default:
            break;
    }
    screen.setOrigin(newOrigin);
    screen.setLeftSide(newLeft);
    screen.setBottomSide(newBottom);
    _camera->setScreen(screen);
}

void RayTracer::Scene::makeRender(void)
{
    unsigned int nbThreads = std::max(std::thread::hardware_concurrency(), static_cast<unsigned int>(1));
    std::size_t nbLines = _camera->getScreenHeight();
    std::size_t nbCols = _camera->getScreenWidth();
    std::vector<std::thread> threads;

    _pixels.resize(nbLines);
    for (std::size_t i = 0; i < nbLines; i++) {
        _pixels[i].resize(nbCols);
    }

    std::size_t linesPerThread = nbLines / nbThreads;
    std::size_t remainingLines = nbLines % nbThreads;

    for (std::size_t i = 0; i < nbThreads; i++) {
        std::size_t startLine = i * linesPerThread + std::min(i, remainingLines);
        std::size_t linesToProcess = linesPerThread + (i < remainingLines ? 1 : 0);
        threads.emplace_back(&RayTracer::Scene::_renderThreading, this, startLine, linesToProcess);
    }

    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    // _scale4();
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

HitPrimitives RayTracer::Scene::_getHitPrimitive(RayTracer::Ray ray)
{
    HitPrimitives hitPrimitives;
    std::pair<RayTracer::IPrimitive *, std::vector<double>> tmp;
    std::vector<double> tValues;

    for (auto it = _primitives.begin(); it != _primitives.end(); it++) {
        tValues = (*it)->hits(ray);
        if (tValues.empty() || tValues.size() < 2) {
            continue;
        }
        hitPrimitives.push_back({it->get(), tValues});
    }
    if (!hitPrimitives.empty()) {
        for (int i = 0; static_cast<std::size_t>(i + 1) < hitPrimitives.size(); i++) {
            if (hitPrimitives[i].second.size() < 2 || hitPrimitives[i + 1].second.size() < 2) {
                continue;
            }
            if (hitPrimitives[i].second[1] > hitPrimitives[i + 1].second[1]) {
                tmp = hitPrimitives[i];
                hitPrimitives[i] = hitPrimitives[i + 1];
                hitPrimitives[i + 1] = tmp;
                i = -1;
            }
        }
    }
    return hitPrimitives;
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

std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> RayTracer::Scene::_getColor(RayTracer::IPrimitive *primitive, double determinant, RayTracer::Ray ray)
{
    if (primitive == nullptr) {
        return {0, 0, 0, 255};
    }

    Math::Vector3D hitPosition = (ray.getDirection() * determinant) + ray.getOrigin();
    Math::Vector3D normal = primitive->getNormalAt(hitPosition);
    Math::Vector3D lightDirection;
    Math::Point3D shadowOrigin;
    RayTracer::Ray shadowRay;
    double light;
    double diffuseFactor = _diffuseFactor;
    bool inShadow;

    shadowOrigin = hitPosition + normal * 1e-4;

    if (_lights.empty()) {
        return primitive->getColor();
    }

    lightDirection = _lights[0]->getDirection() * -1;
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

std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> RayTracer::Scene::_applyLightOnPixel(RayTracer::IPrimitive *primitive, double light)
{
    std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> color = primitive->getColor();

    color = {
        std::min(static_cast<int>(std::get<0>(color) * light), static_cast<int>(std::get<3>(color))),
        std::min(static_cast<int>(std::get<1>(color) * light), static_cast<int>(std::get<3>(color))),
        std::min(static_cast<int>(std::get<2>(color) * light), static_cast<int>(std::get<3>(color))),
        std::get<3>(color)
    };
    return color;
}

void RayTracer::Scene::_renderThreading(std::size_t yStart, std::size_t nbStep)
{
    std::vector<std::pair<RayTracer::IPrimitive *, std::vector<double>>> hitPrimitives;
    std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> color;
    RayTracer::Ray ray;
    double u;
    double v;
    double yAxis = _camera->getScreenHeight();
    double xAxis = _camera->getScreenWidth();

    for (double y = yStart; y < yStart + nbStep && y < yAxis; y++) {
        for (double x = 0; x < xAxis; x++) {
            u = x / xAxis;
            v = y / yAxis;
            ray = _camera->ray(u, v);

            hitPrimitives = _getHitPrimitive(ray);
            if (hitPrimitives.empty()) {
                std::lock_guard<std::mutex> lock(_pixelsMutex);
                _pixels[y][x] = {0, 0, 0, 255};
                continue;
            }

            color = _getPrimitiveColor(hitPrimitives, 0, ray);
            std::lock_guard<std::mutex> lock(_pixelsMutex);
            _pixels[y][x] = color;
        }
    }
}

Color RayTracer::Scene::_getPrimitiveColor(HitPrimitives hitPrimitives, std::size_t index, RayTracer::Ray ray, std::size_t depth)
{
    if (hitPrimitives.empty() || index >= hitPrimitives.size() ||
        hitPrimitives[index].first == nullptr) {
        return {0, 0, 0, 255};
    }
    if (hitPrimitives[index].first->isHavingReflection() && depth < 5) {
        return _handleReflectColor(hitPrimitives, index, ray, depth);
    } else {
        return _handleFlatColor(hitPrimitives, index, ray);
    }
}

Color RayTracer::Scene::_handleFlatColor(HitPrimitives hitPrimitives, std::size_t index, RayTracer::Ray ray)
{
    if (hitPrimitives.empty() || index >= hitPrimitives.size() ||
        hitPrimitives[index].first == nullptr ||
        hitPrimitives[index].second.size() < 2) {
        return {0, 0, 0, 255};
    }

    Color tmpColor = _getColor(hitPrimitives[index].first, hitPrimitives[index].second[1], ray);
    Color color = tmpColor;
    double remainingOpacity;

    std::size_t currentIndex = index + 1;

    if (std::get<3>(tmpColor) < 255) {
        int maxIterations = 10;
        int iterations = 0;

        while (std::get<3>(color) < 255 && currentIndex < hitPrimitives.size() && iterations < maxIterations) {
            if (currentIndex >= hitPrimitives.size() || hitPrimitives[currentIndex].first == nullptr || hitPrimitives[currentIndex].second.size() < 2) {
                continue;
            }

            tmpColor = _getPrimitiveColor(hitPrimitives, currentIndex, ray);
            remainingOpacity = static_cast<double>(255.0 - std::get<3>(color)) / 255.0;
            color = {
                std::get<0>(color) + (std::get<0>(tmpColor) * remainingOpacity),
                std::get<1>(color) + (std::get<1>(tmpColor) * remainingOpacity),
                std::get<2>(color) + (std::get<2>(tmpColor) * remainingOpacity),
                std::min(255.0, std::get<3>(color) + static_cast<double>(std::get<3>(tmpColor)))
            };

            currentIndex++;
            iterations++;
        }
    }

    return color;
}

Color RayTracer::Scene::_handleReflectColor(HitPrimitives hitPrimitives, std::size_t index, RayTracer::Ray ray, std::size_t depth)
{
    if (hitPrimitives.empty() || index >= hitPrimitives.size() || hitPrimitives[index].first == nullptr || depth >= 5) {
        return {0, 0, 0, 255};
    }
    Color color = _handleFlatColor(hitPrimitives, index, ray);
    RayTracer::Ray reflectionRay = hitPrimitives[index].first->getReflectionVector(ray);
    if (reflectionRay == RayTracer::Ray()) {
        return {0, 0, 0, 255};
    }
    HitPrimitives newHitPrimitives = _getHitPrimitive(reflectionRay);
    Color reflectionColor = {0, 0, 0, 255};
    if (!newHitPrimitives.empty() && depth < 5) {
        reflectionColor = _getPrimitiveColor(newHitPrimitives, 0, reflectionRay, depth + 1);
    }
    double reflectionIntensity = hitPrimitives[index].first->getReflectionIntensity();

    Color newColor ={
        static_cast<uint8_t>((1 - reflectionIntensity) * std::get<0>(color) + (reflectionIntensity * std::get<0>(reflectionColor))),
        static_cast<uint8_t>((1 - reflectionIntensity) * std::get<1>(color) + (reflectionIntensity * std::get<1>(reflectionColor))),
        static_cast<uint8_t>((1 - reflectionIntensity) * std::get<2>(color) + (reflectionIntensity * std::get<2>(reflectionColor))),
        std::get<3>(color)
    };
    return newColor;
}

void RayTracer::Scene::_scale2()
{
    std::vector<std::vector<Color>> newPixels;
    std::vector<std::vector<Color>> tmpOutput;
    std::vector<Color> tmp;

    newPixels.resize(_pixels.size() * 2);
    for (std::size_t i = 0; i < _pixels.size(); i++) {
        for (std::size_t j = 0; j < _pixels[i].size(); j++) {
            tmpOutput = _getAroundColor(j, i);
            std::vector<Color> scalePixels = _getScale2Color(tmpOutput);
            for (std::size_t x = 0; x < 4; x++) {
                newPixels[(i * 2) + (x / 2)].push_back(scalePixels[x]);
            }
        }
    }
    _pixels = newPixels;
}

void RayTracer::Scene::_scale3()
{
    std::vector<std::vector<Color>> newPixels;
    std::vector<std::vector<Color>> tmpOutput;
    std::vector<Color> tmp;

    newPixels.resize(_pixels.size() * 3);
    for (std::size_t i = 0; i < _pixels.size(); i++) {
        for (std::size_t j = 0; j < _pixels[i].size(); j++) {
            tmpOutput = _getAroundColor(j, i);
            std::vector<Color> scalePixels = _getScale3Color(tmpOutput);
            for (std::size_t x = 0; x < 9; x++) {
                newPixels[(i * 3) + (x / 3)].push_back(scalePixels[x]);
            }
        }
    }
    _pixels = newPixels;
}

void RayTracer::Scene::_scale4()
{
    _scale2();
    _scale2();
}

std::vector<std::vector<Color>> RayTracer::Scene::_getAroundColor(int i, int j)
{
    std::vector<std::vector<Color>> output;

    output.resize(3);
    for (int x = -1; x < 2; x++) {
        if (j + x < 0 || j + x >= static_cast<int>(_pixels.size())) {
            output[x + 1] = {{0, 0, 0, 255}, {0, 0, 0, 255}, {0, 0, 0, 255}};
            continue;
        }
        for (int y = -1; y < 2; y++) {
            if (i + y < 0 || i + y >= static_cast<int>(_pixels[j + x].size())) {
                output[x + 1].push_back({0, 0, 0, 255});
            } else {
                output[x + 1].push_back(_pixels[j + x][i + y]);
            }
        }
    }
    return output;
}

std::vector<Color> RayTracer::Scene::_getScale2Color(std::vector<std::vector<Color>> colors)
{
    Color B = colors[0][1];
    Color D = colors[1][0];
    Color E = colors[1][1];
    Color F = colors[1][2];
    Color H = colors[2][1];

    if (B != H && D != F) {
        return {
            D == B ? D : E,
            B == F ? F : E,
            D == H ? D : E,
            H == F ? F : E,
        };
    } else {
        return {
            E,
            E,
            E,
            E,
        };
    }
}

std::vector<Color> RayTracer::Scene::_getScale3Color(std::vector<std::vector<Color>> colors)
{
    Color A = colors[0][0];
    Color B = colors[0][1];
    Color C = colors[0][2];
    Color D = colors[1][0];
    Color E = colors[1][1];
    Color F = colors[1][2];
    Color G = colors[2][0];
    Color H = colors[2][1];
    Color I = colors[2][2];

    if (B != H && D != F) {
        return {
            D == B ? D : E,
            (D == B && E != C) || (B == F && E != A) ? B : E,
            B == F ? F : E,
            (D == B && E != G) || (D == H && E != A) ? D : E,
            E,
            (B == F && E != I) || (H == F && E != C) ? F : E,
            D == H ? D : E,
            (D == H && E != I) || (H == F && E != G) ? H : E,
            H == F ? F : E,
        };
    } else {
        return {E, E, E, E, E, E, E, E, E};
    }
}
