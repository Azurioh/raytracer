/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Core
*/

#include "Core.hh"

RayTracer::Core::Core(): _scene(std::make_unique<RayTracer::Scene>()), _gui(std::make_unique<RayTracer::GUI>(_scene->getPixels()))
{
}

void RayTracer::Core::start(void)
{
    RayTracer::Scene::CameraMovement movement;

    while (_gui->isOpen()) {
        movement = _gui->render();
        if (movement == RayTracer::Scene::CameraMovement::WINDOW_CLOSED) {
            break;
        }
        if (movement == RayTracer::Scene::NOTHING) {
            continue;
        }
        _scene->moveCamera(movement);
        _scene->makeRender();
        _gui->refresh(_scene->getPixels());
    }
}
