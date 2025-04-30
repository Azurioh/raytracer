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

std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> RayTracer::Primitives::APrimitive::getColor(void) const
{
	return _color;
}
