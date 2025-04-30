/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Camera
*/

#include "Camera.hh"
#include "Math/Point3D/Point3D.hh"
#include "Math/Vector3D/Vector3D.hh"

RayTracer::Camera::Camera(): _origin(0, 0, 1900)
{
    double width = 1920;
    double height = 1080;

    _screen.setOrigin(Math::Point3D(-(width / 2), -(height / 2), 0));
    _screen.setBottomSide(Math::Vector3D(width, 0, 0));
    _screen.setLeftSide(Math::Vector3D(0, height, 0));
}

Math::Point3D RayTracer::Camera::getOrigin(void) const
{
    return _origin;
}

RayTracer::Screen RayTracer::Camera::getScreen(void) const
{
	return _screen;
}

void RayTracer::Camera::setOrigin(const Math::Point3D& origin)
{
	_origin = origin;
}

void RayTracer::Camera::setScreen(const RayTracer::Screen& screen)
{
	_screen = screen;
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
