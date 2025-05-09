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
    /**
     * @class APrimitive
     *
     * @brief Abstract primitive class
     */
    class APrimitive : public IPrimitive {
        public:
            /**
             * @brief Construct a new APrimitive object
             *
             * @param center The center of the primitive
             */
            APrimitive(Math::Point3D center = Math::Point3D(0, 0, 0));

            /**
             * @brief Get the center of the primitive
             *
             * @return Math::Point3D The center of the primitive
             */
            Math::Point3D getCenter(void) const;

            /**
             * @brief Get the rotation of the primitive
             *
             * @return Math::Vector3D The rotation of the primitive
             */
            Math::Vector3D getRotation(void) const;

            /**
             * @brief Get the color of the primitive
             *
             * @return std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> The color of the primitive
             */
            std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> getColor(void) const;

            /**
             * @brief Check if the primitive has reflection
             *
             * @return true The primitive has reflection
             * @return false The primitive does not have reflection
             */
            bool isHavingReflection(void) const;

            /**
             * @brief Get the reflection intensity of the primitive
             *
             * @return double The reflection intensity of the primitive
             */
            double getReflectionIntensity(void) const;

            /**
             * @brief Check if the primitive has refraction
             *
             * @return true The primitive has refraction
             * @return false The primitive does not have refraction
             */
            bool isHavingRefraction(void) const;

            /**
             * @brief Get the refraction intensity of the primitive
             *
             * @return double The refraction intensity of the primitive
             */
            double getRefractionIntensity(void) const;

            /**
             * @brief Set the center of the primitive
             *
             * @param center The center of the primitive
             */
            void setCenter(Math::Point3D const& center);

            /**
             * @brief Set the rotation of the primitive
             *
             * @param rotation The rotation of the primitive
             */
            void setRotation(Math::Vector3D const& rotation);

            /**
             * @brief Set the color of the primitive
             *
             * @param color The color of the primitive
             */
            void setColor(std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> color);

            /**
             * @brief Set the reflection of the primitive
             *
             * @param havingReflection The reflection of the primitive
             */
            void setHavingReflection(bool havingReflection);

            /**
             * @brief Set the reflection intensity of the primitive
             *
             * @param reflectionIntensity The reflection intensity of the primitive
             */
            void setReflectionIntensity(double reflectionIntensity);

            /**
             * @brief Set the refraction of the primitive
             *
             * @param havingRefraction The refraction of the primitive
             */
            void setHavingRefraction(bool havingRefraction);

            /**
             * @brief Set the refraction intensity of the primitive
             *
             * @param refractionIntensity The refraction intensity of the primitive
             */
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
