/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Screen
*/

#include "Screen.hh"

RayTracer::Screen::Screen()
{
}

RayTracer::Screen::Screen(const Math::Point3D& origin, const Math::Vector3D& bottomSide, const Math::Vector3D& leftSide): _origin(origin)
{
    _bottomSide = bottomSide;
    _leftSide = leftSide;
}

RayTracer::Screen::~Screen()
{
}

Math::Point3D RayTracer::Screen::getOrigin(void) const
{
    return _origin;
}

Math::Vector3D RayTracer::Screen::getBottomSide(void) const
{
	return _bottomSide;
}

Math::Vector3D RayTracer::Screen::getLeftSide(void) const
{
	return _leftSide;
}

void RayTracer::Screen::setOrigin(const Math::Point3D& point)
{
	_origin = point;
}

void RayTracer::Screen::setBottomSide(const Math::Vector3D& vector)
{
	_bottomSide = vector;
}

void RayTracer::Screen::setLeftSide(const Math::Vector3D& vector)
{
	_leftSide = vector;
}

Math::Point3D RayTracer::Screen::pointAt(double u, double v)
{
    Math::Point3D result = _origin;
    Math::Vector3D movement(_bottomSide.length() * u, _leftSide.length() * v, 0);

    result += movement;
    return result;
}
