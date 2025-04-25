/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Core
*/

#pragma once

#include <memory>

#include "RayTracer/Camera/Camera.hh"
#include "RayTracer/GUI/GUI.hh"
#include "RayTracer/Primitives/Sphere/Sphere.hh"

class Core {
    public:
        Core();
        ~Core();

        void start(void);

    private:
        std::vector<RayTracer::Primitives::Sphere> _spheres;
        RayTracer::Camera _camera;
        sf::Image _pixelView;
        std::unique_ptr<RayTracer::GUI> _gui;
};
