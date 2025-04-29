/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Core
*/

#include "Core.hh"

Core::Core(): _camera()
{
    RayTracer::Screen screen = _camera.getScreen();

    _pixelView.create(screen.getBottomSide().length(), screen.getLeftSide().length());
    _spheres = {
        RayTracer::Primitives::Sphere(Math::Point3D(0, 0, -100), 200),
        RayTracer::Primitives::Sphere(Math::Point3D(200, 100, 100), 20),
    };
    _gui = std::unique_ptr<RayTracer::GUI>(new RayTracer::GUI(_spheres, _camera, _pixelView, "SFML", 8));
}

Core::~Core()
{
}

void Core::start(void)
{
    while (_gui->isOpen()) {
        _gui->render();
    }
}
