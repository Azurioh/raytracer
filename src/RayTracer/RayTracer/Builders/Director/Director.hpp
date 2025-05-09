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
    /**
     * @class Director
     *
     * @brief Director for the primitive builders
     */
    class Director {
        public:
            Director() = default;
            ~Director() = default;

            template <typename T>
            /**
             * @brief Make a primitive
             *
             * @param builder The builder to use
             * @param center The center of the primitive
             * @param color The color of the primitive
             * @param reflection The reflection of the primitive
             * @param refraction The refraction of the primitive
             * @param rotation The rotation of the primitive
             * @param ... The arguments to build the primitive size
             */
            void makePrimitive(IPrimitiveBuilder<T>& builder, Math::Point3D const& center, Color color,
                std::pair<bool, double> reflection, std::pair<bool, double> refraction, Math::Vector3D const& rotation, int n = 0, ...)
            {
                std::va_list args;

                builder.reset();
                va_start(args, n);
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
