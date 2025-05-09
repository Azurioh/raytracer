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
    /**
     * @class IPrimitive
     *
     * @brief Interface for the primitives
     */
    class IPrimitive {
        public:
            /**
             * @brief Default constructor for the IPrimitive object
             */
            IPrimitive() = default;

            /**
             * @brief Default destructor for the IPrimitive object
             */
            virtual ~IPrimitive() = default;

            /**
             * @brief Get the center of the primitive
             *
             * @return Math::Point3D The center of the primitive
             */
            virtual Math::Point3D getCenter(void) const = 0;

            /**
             * @brief Get the rotation of the primitive
             *
             * @return Math::Vector3D The rotation of the primitive
             */
            virtual Math::Vector3D getRotation(void) const = 0;

            /**
             * @brief Get the color of the primitive
             *
             * @return std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> The color of the primitive
             */
            virtual std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> getColor(void) const = 0;

            /**
             * @brief Check if the primitive has reflection
             *
             * @return true The primitive has reflection
             * @return false The primitive does not have reflection
             */
            virtual bool isHavingReflection(void) const = 0;

            /**
             * @brief Get the reflection intensity of the primitive
             *
             * @return double The reflection intensity of the primitive
             */
            virtual double getReflectionIntensity(void) const = 0;

            /**
             * @brief Check if the primitive has refraction
             *
             * @return true The primitive has refraction
             * @return false The primitive does not have refraction
             */
            virtual bool isHavingRefraction(void) const = 0;

            /**
             * @brief Get the refraction intensity of the primitive
             *
             * @return double The refraction intensity of the primitive
             */
            virtual double getRefractionIntensity(void) const = 0;

            /**
             * @brief Set the center of the primitive
             *
             * @param center The center of the primitive
             */
            virtual void setCenter(Math::Point3D const& center) = 0;

            /**
             * @brief Set the rotation of the primitive
             *
             * @param rotation The rotation of the primitive
             */
            virtual void setRotation(Math::Vector3D const& rotation) = 0;

            /**
             * @brief Set the color of the primitive
             *
             * @param color The color of the primitive
             */
            virtual void setColor(std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> color) = 0;

            /**
             * @brief Set the reflection of the primitive
             *
             * @param havingReflection The reflection of the primitive
             */
            virtual void setHavingReflection(bool havingReflection) = 0;

            /**
             * @brief Set the reflection intensity of the primitive
             *
             * @param reflectionIntensity The reflection intensity of the primitive
             */
            virtual void setReflectionIntensity(double reflectionIntensity) = 0;

            /**
             * @brief Set the refraction of the primitive
             *
             * @param havingRefraction The refraction of the primitive
             */
            virtual void setHavingRefraction(bool havingRefraction) = 0;

            /**
             * @brief Set the refraction intensity of the primitive
             *
             * @param refractionIntensity The refraction intensity of the primitive
             */
            virtual void setRefractionIntensity(double refractionIntensity) = 0;

            /**
             * @brief Get the hits of the primitive
             *
             * @param ray The ray to check
             * @return std::vector<double> The hits of the primitive
             */
            virtual std::vector<double> hits(RayTracer::Ray const& ray) const = 0;

            /**
             * @brief Get the reflection vector of the primitive
             *
             * @param ray The ray to check
             * @return RayTracer::Ray The reflection vector of the primitive
             */
            virtual RayTracer::Ray getReflectionVector(RayTracer::Ray const& ray) const = 0;

            /**
             * @brief Get the normal at the hit point of the primitive
             *
             * @param hitPoint The hit point of the primitive
             * @return Math::Vector3D The normal at the hit point of the primitive
             */
            virtual Math::Vector3D getNormalAt(const Math::Point3D& hitPoint) const = 0;
    };
}
