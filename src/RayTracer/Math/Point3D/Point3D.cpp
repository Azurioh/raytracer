/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Point3D
*/

#include "Point3D.hh"

Math::Point3D::Point3D(double x, double y, double z): _x(x), _y(y), _z(z)
{
}

Math::Point3D::Point3D(const Vector3D &vector): _x(vector.getX()), _y(vector.getY()), _z(vector.getZ())
{
}

Math::Point3D::Point3D(const Point3D &point): _x(point.getX()), _y(point.getY()), _z(point.getZ())
{
}

double Math::Vector3D::getX(void) const
{
	return _x;
}

double Math::Vector3D::getY(void) const
{
	return _y;
}

double Math::Vector3D::getZ(void) const
{
	return _z;
}

Math::Point3D Math::Point3D::operator+(const Vector3D& vector) const
{
    return Math::Vector3D(_x + vector.getX(), _y + vector.getY(), _z + vector.getZ());
}

Math::Point3D& Math::Point3D::operator+=(const Vector3D& vector)
{
    _x += vector.getX();
    _y += vector.getY();
    _z += vector.getZ();
}

Math::Vector3D Math::Point3D::operator-(const Point3D& point) const
{
    return Math::Vector3D(_x - point.getX(), _y - point.getY(), _z - point.getZ());
}

bool Math::Point3D::operator==(const Point3D& point) const
{
    return (
        _x == point.getX()
            && _y == point.getY()
            && _z == point.getZ()
    );
}

bool Math::Point3D::operator!=(const Point3D& point) const
{
    return !(*this == point);
}

