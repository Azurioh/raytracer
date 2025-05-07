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

    _primitives.push_back(factory.createSphere(Math::Point3D(0, 500, -300), 300));
    _primitives.push_back(factory.createSphere(Math::Point3D(0, 0, -100), 100));
    _primitives.push_back(factory.createSphere(Math::Point3D(-400, 200, -100), 100));
    _primitives.push_back(factory.createSphere(Math::Point3D(400, 200, -100), 100));
    _lights.push_back(std::unique_ptr<RayTracer::Light>(new RayTracer::Light(Math::Vector3D(-1, -1, -1))));

    _primitives[0]->setHavingReflection(true);
    _primitives[0]->setReflectionIntensity(0.5);
    _primitives[1]->setColor({255, 0, 0, 255});
    _primitives[2]->setColor({0, 255, 0, 255});
    _primitives[3]->setColor({255, 255, 0, 255});
    makeRender();
    exportToOutputFile();
}

RayTracer::Scene::~Scene()
{
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

HitPrimitives RayTracer::Scene::_getHitPrimitive(RayTracer::Ray ray, RayTracer::IPrimitive *toExclude)
{
    HitPrimitives hitPrimitives;
    std::pair<RayTracer::IPrimitive *, std::vector<double>> tmp;
    std::vector<double> tValues;

    for (auto it = _primitives.begin(); it != _primitives.end(); it++) {
        tValues = (*it)->hits(ray);
        if (tValues.empty() || tValues.size() < 2 || it->get() == toExclude) {
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
    Math::Vector3D normal = hitPosition - primitive->getCenter();
    Math::Vector3D lightDirection;
    Math::Point3D shadowOrigin;
    RayTracer::Ray shadowRay;
    double light;
    double diffuseFactor = _diffuseFactor;
    bool inShadow;

    normal.normalize();
    shadowOrigin = hitPosition + normal * 1e-4;

    if (_lights.empty()) {
        return primitive->getColor();
    }

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
    if (reflectionRay.getDirection() == Math::Vector3D()) {
        return {0, 0, 0, 255};
    }
    HitPrimitives newHitPrimitives = _getHitPrimitive(reflectionRay, hitPrimitives[index].first);
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
