/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitive
*/

#pragma once

#include "RayTracer/Primitives/IPrimitive.hh"
#include "Math/Vector3D/Vector3D.hh"
#include "Math/Point3D/Point3D.hh"

#include <cstdint>
#include <tuple>

namespace RayTracer::Primitives
{
    class APrimitive : public IPrimitive {
        public:
            APrimitive(Math::Point3D center = Math::Point3D(0, 0, 0));

            Math::Point3D getCenter(void) const;
            Math::Vector3D getRotation(void) const;
            std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> getColor(void) const;
            bool isHavingReflection(void) const;
            double getReflectionIntensity(void) const;
            bool isHavingRefraction(void) const;
            double getRefractionIntensity(void) const;

            void setCenter(Math::Point3D const& center);
            void setRotation(Math::Vector3D const& rotation);
            void setColor(std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> color);
            void setHavingReflection(bool havingReflection);
            void setReflectionIntensity(double reflectionIntensity);
            void setHavingRefraction(bool havingRefraction);
            void setRefractionIntensity(double refractionIntensity);

        protected:
            Math::Point3D _center;
            Math::Vector3D _rotation;
            std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> _color;
            bool _havingReflection;
            double _reflectionIntensity;
            bool _havingRefraction;
            double _refractionIntensity;
    };
}
