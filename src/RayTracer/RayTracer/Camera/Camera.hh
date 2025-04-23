/*
** EPITECH PROJECT, 2025
** bs-raytracer
** File description:
** Camera
*/

#pragma once

#include "Math/Point3D/Point3D.hh"
#include "Ray/Ray.hh"
#include "Screen/Screen.hh"

namespace RayTracer
{
    class Camera
    {
        public:
            Camera();
            ~Camera() = default;

            Math::Point3D getOrigin(void) const;
            RayTracer::Screen getScreen(void) const;

            void setOrigin(const Math::Point3D& origin);
            void setScreen(const RayTracer::Screen& screen);

            RayTracer::Ray ray(double u, double v);
            void moveCamera(Math::Vector3D movement);

        private:
            Math::Point3D _origin;
            RayTracer::Screen _screen;
    };
}
