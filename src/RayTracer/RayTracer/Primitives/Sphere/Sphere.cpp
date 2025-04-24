/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include <cmath>
#include "Sphere.hh"

RayTracer::Primitives::Sphere::Sphere(Math::Point3D center, double radius): center(center), radius(radius)
{
}

RayTracer::Primitives::Sphere::~Sphere()
{
}

std::vector<double> RayTracer::Primitives::Sphere::hits(RayTracer::Ray const &ray) const
{
    Math::Vector3D oc = ray.getOrigin() - center;
    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2.0 * oc.dot(ray.getDirection());
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0)
        return {};

    return {
        (-b + std::sqrt(discriminant)) / (2.0 * a),
        (-b - std::sqrt(discriminant)) / (2.0 * a),
    };
}
