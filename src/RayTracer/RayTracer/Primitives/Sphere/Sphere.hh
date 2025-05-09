/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#pragma once

#include "RayTracer/Primitives/APrimitive.hh"
#include "Math/Vector3D/Vector3D.hh"
#include "Math/Point3D/Point3D.hh"
#include "RayTracer/Ray/Ray.hh"

#include <vector>

namespace RayTracer::Primitives
{
    /**
     * @class Sphere
     *
     * @brief Sphere class
     */
    class Sphere : public APrimitive
    {
        public:
            /**
             * @brief Construct a new Sphere object
             *
             * @param center The center of the sphere
             * @param radius The radius of the sphere
             */
            Sphere(Math::Point3D center = Math::Point3D(0, 0, 0), double radius = 0);

            /**
             * @brief Destroy the Sphere object
             */
            ~Sphere();

            /**
             * @brief Get the reflection vector of the sphere
             *
             * @param ray The ray to check
             * @return RayTracer::Ray The reflection vector of the sphere
             */
            RayTracer::Ray getReflectionVector(RayTracer::Ray const& ray) const override;

            /**
             * @brief Get the hits of the sphere
             *
             * @param ray The ray to check
             * @return std::vector<double> The hits of the sphere
             */
            std::vector<double> hits(RayTracer::Ray const &ray) const override;

            /**
             * @brief Get the normal at the hit point of the sphere
             *
             * @param hitPoint The hit point of the sphere
             * @return Math::Vector3D The normal at the hit point of the sphere
             */
            Math::Vector3D getNormalAt(const Math::Point3D& hitPoint) const override;

            /**
             * @brief Set the radius of the sphere
             *
             * @param radius The radius of the sphere
             */
            void setRadius(double radius);

        private:
            double _radius;
    };
}
