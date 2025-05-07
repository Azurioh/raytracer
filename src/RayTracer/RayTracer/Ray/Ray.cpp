/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Ray
*/

#include "Ray.hh"

RayTracer::Ray::Ray(Math::Point3D& origin, Math::Vector3D& direction): _origin(origin), _direction(direction)
{
}

Math::Point3D RayTracer::Ray::getOrigin(void) const
{
	return _origin;
}

Math::Vector3D RayTracer::Ray::getDirection(void) const
{
	return _direction;
}

void RayTracer::Ray::setOrigin(const Math::Point3D& origin)
{
	_origin = origin;
}

void RayTracer::Ray::setDirection(const Math::Vector3D& direction)
{
	_direction = direction;
}

bool RayTracer::Ray::operator==(const RayTracer::Ray& ray) const
{
	return (_origin == ray.getOrigin() && _direction == ray.getDirection());
}
