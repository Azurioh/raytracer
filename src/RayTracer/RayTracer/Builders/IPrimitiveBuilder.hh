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

using Color = std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>;

namespace RayTracer::Builders
{
    template <typename T>
    class IPrimitiveBuilder {
        public:
            IPrimitiveBuilder() = default;
            virtual ~IPrimitiveBuilder() = default;
            virtual void reset() = 0;
            virtual void buildCenter(Math::Point3D const& center) = 0;
            virtual void buildRotation(Math::Vector3D const& rotation) = 0;
            virtual void buildColor(Color color) = 0;
            virtual void buildSize(std::va_list& args) = 0;
            virtual void buildReflection(double intensity) = 0;
            virtual void buildRefraction(double intensity) = 0;
            virtual std::unique_ptr<T>& getPrimitive() = 0;
    };
}
