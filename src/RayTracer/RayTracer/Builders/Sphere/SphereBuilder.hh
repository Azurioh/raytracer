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
    /**
     * @class SphereBuilder
     *
     * @brief Builder for the sphere primitive
     */
    class SphereBuilder : public APrimitiveBuilder<RayTracer::Primitives::Sphere> {
        public:
            /**
             * @brief Default constructor for the SphereBuilder class
             */
            SphereBuilder();

            /**
             * @brief Default destructor for the SphereBuilder class
             */
            ~SphereBuilder();

            /**
             * @brief Reset the builder
             */
            void reset();

            /**
             * @brief Build the center of the sphere
             *
             * @param center The center of the sphere
             */
            void buildCenter(Math::Point3D const& center);

            /**
             * @brief Build the rotation of the sphere
             *
             * @param rotation The rotation of the sphere
             */
            void buildRotation(Math::Vector3D const& rotation);

            /**
             * @brief Build the color of the sphere
             *
             * @param color The color of the sphere
             */
            void buildColor(Color color);

            /**
             * @brief Build the size of the sphere
             *
             * @param args The arguments to build the size (radius)
             */
            void buildSize(va_list& args);

            /**
             * @brief Build the reflection of the sphere
             *
             * @param intensity The reflection intensity
             */
            void buildReflection(double intensity);

            /**
             * @brief Build the refraction of the sphere
             *
             * @param intensity The refraction intensity
             */
            void buildRefraction(double intensity);
    };
}
