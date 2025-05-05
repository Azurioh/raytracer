/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitive
*/

#pragma once

#include <cstdint>
#include <tuple>
#include "Math/Point3D/Point3D.hh"
#include "RayTracer/Primitives/IPrimitive.hh"

namespace RayTracer
{
    namespace Primitives
    {
        class APrimitive : public IPrimitive {
            public:
                APrimitive(Math::Point3D center = Math::Point3D(0, 0, 0));

                Math::Point3D getCenter(void) const;
                std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> getColor(void) const;
                void setColor(std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> color);

            protected:
                Math::Point3D _center;
                std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> _color;
        };
    }
}
