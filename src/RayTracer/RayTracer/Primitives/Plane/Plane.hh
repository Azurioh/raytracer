/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Plane.hpp
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
     * @class Plane
     * @brief Class representing a plane flat object.
     */
    class Plane : public APrimitive
    {
        public:
            /**
             * @brief Create a new Plane object.
             *
             * @param center The center point of the plane.
             * @param normal The normal vector of the plane.
             */
            Plane(Math::Point3D center = Math::Point3D(0, 0, 0), Math::Vector3D normal = Math::Vector3D(0, 1, 0));

            /**
             * @brief Get the reflection vector of the ray on the plane.
             *
             * @param ray The ray to reflect.
             * @return The reflection ray.
             */
            RayTracer::Ray getReflectionVector(RayTracer::Ray const& ray) const override;

            /**
             * @brief Calculate the intersection points of a ray with the plane.
             *
             * @param ray The ray to check for intersections.
             * @return A vector of intersection points (t values).
             */
            std::vector<double> hits(RayTracer::Ray const &ray) const override;

            /**
             * @brief Get the normal vector at a specific hit point on the plane.
             *
             * @param hitPoint The point at which to get the normal vector.
             * @return The normal vector at the hit point.
             */
            Math::Vector3D getNormalAt(const Math::Point3D& hitPoint) const override;

            /**
             * @brief Get the normal vector of the plane.
             *
             * @return The normal vector of the plane.
             */
            Math::Vector3D getNormal() const;

            /**
             * @brief Set the normal vector of the plane.
             *
             * @param normal The new normal vector of the plane.
             */
            void setNormal(const Math::Vector3D& normal);

        private:
            Math::Vector3D _normal; /*!> The normal vector of the plane */
    };
}
