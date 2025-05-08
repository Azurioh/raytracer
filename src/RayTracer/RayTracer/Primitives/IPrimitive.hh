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
#include "Math/Vector3D/Vector3D.hh"
#include "RayTracer/Ray/Ray.hh"

namespace RayTracer
{
    class IPrimitive {
        public:
            IPrimitive() = default;
            virtual ~IPrimitive() = default;

            virtual Math::Point3D getCenter(void) const = 0;
            virtual Math::Vector3D getRotation(void) const = 0;
            virtual std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> getColor(void) const = 0;
            virtual bool isHavingReflection(void) const = 0;
            virtual double getReflectionIntensity(void) const = 0;
            virtual bool isHavingRefraction(void) const = 0;
            virtual double getRefractionIntensity(void) const = 0;

            virtual void setCenter(Math::Point3D const& center) = 0;
            virtual void setRotation(Math::Vector3D const& rotation) = 0;
            virtual void setColor(std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> color) = 0;
            virtual void setHavingReflection(bool havingReflection) = 0;
            virtual void setReflectionIntensity(double reflectionIntensity) = 0;
            virtual void setHavingRefraction(bool havingRefraction) = 0;
            virtual void setRefractionIntensity(double refractionIntensity) = 0;

            virtual std::vector<double> hits(RayTracer::Ray const& ray) const = 0;
            virtual RayTracer::Ray getReflectionVector(RayTracer::Ray const& ray) const = 0;
            virtual Math::Vector3D getNormalAt(const Math::Point3D& hitPoint) const = 0;
    };
}
