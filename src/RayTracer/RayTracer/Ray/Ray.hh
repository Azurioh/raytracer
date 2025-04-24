/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Ray
*/

#pragma once

#include "Math/Point3D/Point3D.hh"
#include "Math/Vector3D/Vector3D.hh"

namespace RayTracer
{
    class Ray {
        public:
            Ray() = default;
            Ray(Math::Point3D& origin, Math::Vector3D& direction);
            ~Ray() = default;

            Math::Point3D getOrigin(void) const;
            Math::Vector3D getDirection(void) const;

            void setOrigin(const Math::Point3D& origin);
            void setDirection(const Math::Vector3D& direction);

        private:
            Math::Point3D _origin;
            Math::Vector3D _direction;
    };
}
