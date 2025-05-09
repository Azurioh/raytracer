/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IPrimitiveBuilder
*/

#pragma once

#include "Math/Point3D/Point3D.hh"
#include "Math/Vector3D/Vector3D.hh"
#include <cstdarg>
#include <memory>
#include <tuple>
#include <cstdint>

using Color = std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>;

namespace RayTracer::Builders
{
    template <typename T>
    /**
     * @class IPrimitiveBuilder
     *
     * @brief Interface for primitive builders
     *
     * @tparam T The type of the primitive to build
     */
    class IPrimitiveBuilder {
        public:
            /**
             * @brief Default constructor for the IPrimitiveBuilder class
             */
            IPrimitiveBuilder() = default;

            /**
             * @brief Default destructor for the IPrimitiveBuilder class
             */
            virtual ~IPrimitiveBuilder() = default;

            /**
             * @brief Reset the builder
             */
            virtual void reset() = 0;

            /**
             * @brief Build the center of the primitive
             *
             * @param center The center of the primitive
             */
            virtual void buildCenter(Math::Point3D const& center) = 0;

            /**
             * @brief Build the rotation of the primitive
             *
             * @param rotation The rotation of the primitive
             */
            virtual void buildRotation(Math::Vector3D const& rotation) = 0;

            /**
             * @brief Build the color of the primitive
             *
             * @param color The color of the primitive
             */
            virtual void buildColor(Color color) = 0;

            /**
             * @brief Build the size of the primitive
             *
             * @param args The arguments to build the size
             */
            virtual void buildSize(std::va_list& args) = 0;

            /**
             * @brief Build the reflection of the primitive
             *
             * @param intensity The reflection intensity
             */
            virtual void buildReflection(double intensity) = 0;

            /**
             * @brief Build the refraction of the primitive
             *
             * @param intensity The refraction intensity
             */
            virtual void buildRefraction(double intensity) = 0;

            /**
             * @brief Get the primitive built
             *
             * @return The primitive built
             */
            virtual std::unique_ptr<T>& getPrimitive() = 0;
    };
}
