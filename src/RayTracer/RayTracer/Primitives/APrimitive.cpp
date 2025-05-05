/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hh"

RayTracer::Primitives::APrimitive::APrimitive(Math::Point3D center): _center(center)
{
}

Math::Point3D RayTracer::Primitives::APrimitive::getCenter(void) const
{
	return _center;
}

std::tuple<double, double, double, double> RayTracer::Primitives::APrimitive::getColor(void) const
{
	return _color;
}

void RayTracer::Primitives::APrimitive::setColor(std::tuple<double, double, double, double> color)
{
	_color = color;
}
