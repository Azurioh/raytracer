/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include <cmath>
#include "Sphere.hh"
#include "RayTracer/Primitives/IPrimitive.hh"

RayTracer::Primitives::Flat::Sphere::Sphere(Math::Point3D center, double radius): APrimitive(center), _radius(radius)
{
    _color = {255, 0, 0};
}

RayTracer::Primitives::Flat::Sphere::~Sphere()
{
}

std::vector<double> RayTracer::Primitives::Flat::Sphere::hits(RayTracer::Ray const &ray) const
{
    Math::Vector3D oc = ray.getOrigin() - _center;
    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2.0 * oc.dot(ray.getDirection());
    double c = oc.dot(oc) - _radius * _radius;
    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0)
        return {};

    return {
        (-b + std::sqrt(discriminant)) / (2.0 * a),
        (-b - std::sqrt(discriminant)) / (2.0 * a),
    };
}

void RayTracer::Primitives::Flat::Sphere::setRadius(double radius)
{
	_radius = radius;
}
