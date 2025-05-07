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
    _color = {0, 0, 255, 255};
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

RayTracer::Ray RayTracer::Primitives::Flat::Sphere::getReflectionVector(RayTracer::Ray const& ray) const
{
    Math::Vector3D rayDir = ray.getDirection();
    rayDir.normalize();
    Math::Vector3D oc = ray.getOrigin() - _center;

    double a = rayDir.dot(rayDir);
    double b = 2.0 * oc.dot(rayDir);
    double c = oc.dot(oc) - _radius * _radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return RayTracer::Ray();
    }

    double sqrtDiscriminant = std::sqrt(discriminant);
    double t1 = (-b - sqrtDiscriminant) / (2.0 * a);
    double t2 = (-b + sqrtDiscriminant) / (2.0 * a);

    double t = 0;
    if (t1 > 1e-4) {
        t = t1;
    } else if (t2 > 1e-4) {
        t = t2;
    } else {
        return RayTracer::Ray();
    }

    Math::Point3D hitPoint = ray.getOrigin() + rayDir * t;
    Math::Vector3D normal = hitPoint - _center;
    normal.normalize();
    double dot = rayDir.dot(normal);

    Math::Vector3D reflectionDir = rayDir - normal * (2 * dot);
    if (reflectionDir.dot(normal) > 0) {
        reflectionDir *= -1;
    }
    reflectionDir.normalize();
    Math::Point3D reflectionOrigin = hitPoint + normal * 1e-4;
    RayTracer::Ray reflectionRay;
    reflectionRay.setOrigin(reflectionOrigin);
    reflectionRay.setDirection(reflectionDir);
    return reflectionRay;
}
