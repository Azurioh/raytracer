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
    /**
     * @class PlaneBuilder
     *
     * @brief Builder for the plane primitive
     */
    class PlaneBuilder : public APrimitiveBuilder<Primitives::Plane> {
        public:
            /**
             * @brief Default constructor for the PlaneBuilder class
             */
            PlaneBuilder();
            /**
             * @brief Default destructor for the PlaneBuilder class
             */
            ~PlaneBuilder();

            /**
             * @brief Reset the builder
             */
            void reset();

            /**
             * @brief Build the center of the plane
             *
             * @param center The center of the plane
             */
            void buildCenter(Math::Point3D const& center);

            /**
             * @brief Build the rotation of the plane
             *
             * @param rotation The rotation of the plane
             */
            void buildRotation(Math::Vector3D const& rotation);

            /**
             * @brief Build the color of the plane
             *
             * @param color The color of the plane
             */
            void buildColor(Color color);

            /**
             * @brief Build the size of the plane
             *
             * @param args The arguments to build the size (width, height)
             */
            void buildSize(std::va_list& args);

            /**
             * @brief Build the reflection of the plane
             *
             * @param intensity The reflection intensity
             */
            void buildReflection(double intensity);

            /**
             * @brief Build the refraction of the plane
             *
             * @param intensity The refraction intensity
             */
            void buildRefraction(double intensity);
    };
}
