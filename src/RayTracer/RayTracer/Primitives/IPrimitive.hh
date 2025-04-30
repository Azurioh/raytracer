/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IPrimitive
*/

#pragma once

#include <cstdint>
#include <vector>
#include <tuple>
#include "Math/Point3D/Point3D.hh"
#include "RayTracer/Ray/Ray.hh"

namespace RayTracer
{
    class IPrimitive {
        public:
            IPrimitive() = default;
            virtual ~IPrimitive() = default;

            virtual Math::Point3D getCenter(void) const = 0;
            virtual std::vector<double> hits(RayTracer::Ray const &ray) const = 0;
            virtual std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> getColor(void) const = 0;
    };
}
