/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Plane.cpp
*/

#include "Math/Vector3D/Vector3D.hh"
#include "Math/Point3D/Point3D.hh"
#include "Plane.hh"

#include <cmath>

RayTracer::Primitives::Plane::Plane(Math::Point3D center, Math::Vector3D normal): APrimitive(center), _normal(normal)
{
    _normal.normalize();
}

RayTracer::Ray RayTracer::Primitives::Plane::getReflectionVector(RayTracer::Ray const& ray) const
{
    double denom = _normal.dot(ray.getDirection());

    if (std::fabs(denom) < 1e-8) {
        return RayTracer::Ray();
    }

    Math::Vector3D rayToPlane = _center - ray.getOrigin();
    double t = rayToPlane.dot(_normal) / denom;

    if (t < 1e-4) {
        return RayTracer::Ray();
    }

    Math::Vector3D rayDir = ray.getDirection();
    rayDir.normalize();
    Math::Point3D hitPoint = ray.getOrigin() + rayDir * t;

    Math::Vector3D normal = _normal;
    if (rayDir.dot(normal) > 0) {
        normal = normal * -1.0;
    }

    double dot = rayDir.dot(normal);
    Math::Vector3D reflectionDir = rayDir - (normal * (2.0 * dot));
    reflectionDir.normalize();

    Math::Point3D reflectionOrigin = hitPoint + normal * 1e-4;

    RayTracer::Ray reflectionRay;
    reflectionRay.setOrigin(reflectionOrigin);
    reflectionRay.setDirection(reflectionDir);

    return reflectionRay;
}

std::vector<double> RayTracer::Primitives::Plane::hits(RayTracer::Ray const &ray) const
{
    double denom = _normal.dot(ray.getDirection());

    if (std::fabs(denom) < 1e-8) {
        return {};
    }

    Math::Vector3D rayToPlane = _center - ray.getOrigin();
    double t = rayToPlane.dot(_normal) / denom;

    if (t >= 0.0) {
        return {t, t};
    }
    return {};
}

Math::Vector3D RayTracer::Primitives::Plane::getNormalAt(const Math::Point3D& hitPoint __attribute__((unused))) const
{
    return _normal;
}

Math::Vector3D RayTracer::Primitives::Plane::getNormal() const
{
    return _normal;
}

void RayTracer::Primitives::Plane::setNormal(const Math::Vector3D& normal)
{
    _normal = normal;
    _normal.normalize();
}
