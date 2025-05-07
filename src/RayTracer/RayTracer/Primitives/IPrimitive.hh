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
            virtual std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> getColor(void) const = 0;
            virtual bool isHavingReflection(void) const = 0;
            virtual double getReflectionIntensity(void) const = 0;

            virtual void setCenter(Math::Point3D center) = 0;
            virtual void setColor(std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> color) = 0;
            virtual void setHavingReflection(bool havingReflection) = 0;
            virtual void setReflectionIntensity(double reflectionIntensity) = 0;

            virtual std::vector<double> hits(RayTracer::Ray const& ray) const = 0;
            virtual RayTracer::Ray getReflectionVector(RayTracer::Ray const& ray) const = 0;
    };
}
