/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Core
*/

#pragma once

#include <memory>

#include "RayTracer/GUI/GUI.hh"
#include "RayTracer/Scene/Scene.hh"

namespace RayTracer
{
    class Core {
        public:
            Core();
            ~Core() = default;

            void start(void);

        private:
            std::unique_ptr<RayTracer::Scene> _scene;
            std::unique_ptr<RayTracer::GUI> _gui;
    };
}
