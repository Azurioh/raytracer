/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hh"

RayTracer::Primitives::APrimitive::APrimitive(Math::Point3D center): _center(center), _havingReflection(false), _reflectionIntensity(0),
	_havingRefraction(false), _refractionIntensity(0)
{
}

Math::Point3D RayTracer::Primitives::APrimitive::getCenter(void) const
{
	return _center;
}

Math::Vector3D RayTracer::Primitives::APrimitive::getRotation(void) const
{
	return _rotation;
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

bool RayTracer::Primitives::APrimitive::isHavingRefraction(void) const
{
	return _havingRefraction;
}

double RayTracer::Primitives::APrimitive::getRefractionIntensity(void) const
{
	return _refractionIntensity;
}


void RayTracer::Primitives::APrimitive::setCenter(Math::Point3D const& center)
{
	_center = center;
}

void RayTracer::Primitives::APrimitive::setRotation(Math::Vector3D const& rotation)
{
	_rotation = rotation;
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

void RayTracer::Primitives::APrimitive::setHavingRefraction(bool havingRefraction)
{
	_havingRefraction = havingRefraction;
}

void RayTracer::Primitives::APrimitive::setRefractionIntensity(double refractionIntensity)
{
	_refractionIntensity = refractionIntensity;
}
