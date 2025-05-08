/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PlaneBuilder
*/

#pragma once

#include <cstdarg>

#include "RayTracer/Builders/APrimitiveBuilder.hpp"
#include "RayTracer/Primitives/Plane/Plane.hh"

namespace RayTracer::Builders
{
    class PlaneBuilder : public APrimitiveBuilder<Primitives::Plane> {
        public:
            PlaneBuilder();
            ~PlaneBuilder();

            void reset();
            void buildCenter(Math::Point3D const& center);
            void buildRotation(Math::Vector3D const& rotation);
            void buildColor(Color color);
            void buildSize(std::va_list& args);
            void buildReflection(double intensity);
            void buildRefraction(double intensity);
    };
}
