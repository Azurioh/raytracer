/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Light
*/

#include "Light.hh"

RayTracer::Light::Light(Math::Vector3D direction, double intensity, Color color): _direction(direction), _intensity(intensity), _color(color)
{
}

RayTracer::Light::~Light()
{
}

Math::Vector3D RayTracer::Light::getDirection(void) const
{
	return _direction;
}

double RayTracer::Light::getIntensity(void) const
{
	return _intensity;
}

RayTracer::Light::Color RayTracer::Light::getColor(void) const
{
	return _color;
}

void RayTracer::Light::setDirection(Math::Vector3D direction)
{
	_direction = direction;
}

void RayTracer::Light::setIntensity(double intensity)
{
	_intensity = intensity;
}

void RayTracer::Light::setColor(Color color)
{
	_color = color;
}

