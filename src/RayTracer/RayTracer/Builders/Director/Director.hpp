/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Director
*/

#pragma once

#include <iostream>
#include <utility>
#include <cstdarg>
#include "RayTracer/Builders/IPrimitiveBuilder.hh"
#include "RayTracer/Primitives/IPrimitive.hh"

namespace RayTracer::Builders
{
    class Director {
        public:
            Director() = default;
            ~Director() = default;

            template <typename T>
            void makePrimitive(IPrimitiveBuilder<T>& builder, Math::Point3D const& center, Color color,
                std::pair<bool, double> reflection, std::pair<bool, double> refraction, Math::Vector3D const& rotation, ...)
            {
                std::va_list args;

                builder.reset();
                va_start(args, rotation);
                builder.buildCenter(center);
                builder.buildColor(color);
                if (reflection.first) {
                    builder.buildReflection(reflection.second);
                }
                if (refraction.first) {
                    builder.buildRefraction(refraction.second);
                }
                builder.buildRotation(rotation);
                builder.buildSize(args);
                va_end(args);
            }

        private:
    };
}
