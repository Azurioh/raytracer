/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Screen
*/

#include "Screen.hh"

RayTracer::Camera::Screen::Screen()
{
}

RayTracer::Camera::Screen::Screen(const Math::Point3D& origin, const Math::Vector3D& bottomSide, const Math::Vector3D& leftSide)
{
    _origin = origin;
    _bottomSide = bottomSide;
    _leftSide = leftSide;
}

RayTracer::Camera::Screen::~Screen()
{
}

Math::Point3D RayTracer::Camera::Screen::pointAt(double u, double v)
{
    Math::Point3D result = _origin;
    Math::Vector3D movement(_bottomSide.length() * u, _leftSide.length() * v, 0);

    result += movement;
    return result;
}
