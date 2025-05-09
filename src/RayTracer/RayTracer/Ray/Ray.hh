/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Ray
*/

#pragma once

#include "Math/Point3D/Point3D.hh"
#include "Math/Vector3D/Vector3D.hh"

namespace RayTracer
{
    /**
     * @class Ray
     *
     * @brief Ray class
     */
    class Ray {
        public:
            /**
             * @brief Default constructor of the ray
             *
             */
            Ray() = default;

            /**
             * @brief Construct a new Ray object
             *
             * @param origin The origin of the ray
             * @param direction The direction of the ray
             */
            Ray(Math::Point3D& origin, Math::Vector3D& direction);

            /**
             * @brief Default destructor of the ray
             *
             */
            ~Ray() = default;

            /**
             * @brief Get the origin of the ray
             *
             * @return Math::Point3D The origin of the ray
             */
            Math::Point3D getOrigin(void) const;

            /**
             * @brief Get the direction of the ray
             *
             * @return Math::Vector3D The direction of the ray
             */
            Math::Vector3D getDirection(void) const;

            /**
             * @brief Set the origin of the ray
             *
             * @param origin The origin of the ray
             */
            void setOrigin(const Math::Point3D& origin);

            /**
             * @brief Set the direction of the ray
             *
             * @param direction The direction of the ray
             */
            void setDirection(const Math::Vector3D& direction);

            /**
             * @brief Check if the ray is equal to another ray
             *
             * @param ray The ray to compare
             * @return true The ray is equal to the other ray
             * @return false The ray is not equal to the other ray
             */
            bool operator==(const RayTracer::Ray& ray) const;

        private:
            Math::Point3D _origin;
            Math::Vector3D _direction;
    };
}
