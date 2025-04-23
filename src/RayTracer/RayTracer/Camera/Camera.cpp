/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Camera
*/

#include "Camera.hh"
#include "Math/Point3D/Point3D.hh"
#include "Math/Vector3D/Vector3D.hh"

RayTracer::Camera::Camera()
{
    _origin = Math::Point3D(0, 0, 1400);

    _screen.setOrigin(Math::Point3D(-400, -400, 0));
    _screen.setBottomSide(Math::Vector3D(800, 0, 0));
    _screen.setLeftSide(Math::Vector3D(0, 800, 0));
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v)
{
    Math::Point3D screenPoint = _screen.pointAt(u, v);
    Math::Vector3D direction = screenPoint - _origin;
    RayTracer::Ray ray;

    direction.normalize();
    ray.setOrigin(_origin);
    ray.setDirection(direction);
    return ray;
}

void RayTracer::Camera::moveCamera(Math::Vector3D movement)
{
    _origin += movement;
    _screen.setOrigin(_screen.getOrigin() + movement);
}
