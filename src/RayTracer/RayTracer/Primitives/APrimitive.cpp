/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hh"

RayTracer::Primitives::APrimitive::APrimitive(Math::Point3D center): _center(center), _havingReflection(false), _reflectionIntensity(0) {}

Math::Point3D RayTracer::Primitives::APrimitive::getCenter(void) const
{
	return _center;
}

std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> RayTracer::Primitives::APrimitive::getColor(void) const
{
	return _color;
}

bool RayTracer::Primitives::APrimitive::isHavingReflection(void) const
{
	return _havingReflection;
}

double RayTracer::Primitives::APrimitive::getReflectionIntensity(void) const
{
	return _reflectionIntensity;
}

void RayTracer::Primitives::APrimitive::setCenter(Math::Point3D center)
{
	_center = center;
}

void RayTracer::Primitives::APrimitive::setColor(std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> color)
{
	_color = color;
}

void RayTracer::Primitives::APrimitive::setHavingReflection(bool havingReflection)
{
	_havingReflection = havingReflection;
}

void RayTracer::Primitives::APrimitive::setReflectionIntensity(double reflectionIntensity)
{
	_reflectionIntensity = reflectionIntensity;
}
