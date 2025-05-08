/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** SphereBuilder
*/

#pragma once

#include <cstdarg>

#include "RayTracer/Builders/APrimitiveBuilder.hpp"
#include "RayTracer/Primitives/Sphere/Sphere.hh"

namespace RayTracer::Builders
{
    class SphereBuilder : public APrimitiveBuilder<RayTracer::Primitives::Sphere> {
        public:
            SphereBuilder();
            ~SphereBuilder();

            void reset();
            void buildCenter(Math::Point3D const& center);
            void buildRotation(Math::Vector3D const& rotation);
            void buildColor(Color color);
            void buildSize(va_list& args);
            void buildReflection(double intensity);
            void buildRefraction(double intensity);
    };
}
