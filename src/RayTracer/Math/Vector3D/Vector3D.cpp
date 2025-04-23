/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Vector3D
*/

#include <cmath>
#include "Vector3D.hh"
#include "Math/Point3D/Point3D.hh"

Math::Vector3D::Vector3D(double x, double y, double z): _x(x), _y(y), _z(z)
{
}

Math::Vector3D::Vector3D(const Point3D &point)
{
}

Math::Vector3D::Vector3D(const Math::Vector3D &vector): _x(vector.getX()), _y(vector.getY()), _z(vector.getZ())
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

double Math::Vector3D::length(void) const
{
    return std::sqrt(
        std::pow(_x, 2) +
        std::pow(_y, 2) +
        std::pow(_z, 2)
    );
}

double Math::Vector3D::dot(Math::Vector3D const& vector) const
{
    return (_x * vector.getX()) + (_y * vector.getY()) + (_z * vector.getZ());
}

Math::Vector3D Math::Vector3D::operator+(Vector3D const& vector) const
{
    return Math::Vector3D(_x + vector.getX(), _y + vector.getY(), _z + vector.getZ());
}

Math::Vector3D Math::Vector3D::operator-(Vector3D const& vector) const
{
    return Math::Vector3D(_x - vector.getX(), _y - vector.getY(), _z - vector.getZ());
}

Math::Vector3D& Math::Vector3D::operator+=(Vector3D const& vector)
{
    _x += vector.getX();
    _y += vector.getY();
    _z += vector.getZ();
}

Math::Vector3D& Math::Vector3D::operator-=(Vector3D const& vector)
{
    _x -= vector.getX();
    _y -= vector.getY();
    _z -= vector.getZ();
}

Math::Vector3D& Math::Vector3D::operator=(Vector3D const& vector)
{
    _x = vector.getX();
    _y = vector.getY();
    _z = vector.getZ();
}

Math::Vector3D Math::Vector3D::operator*(double const scalar) const
{
    return Math::Vector3D(_x * scalar, _y * scalar, _z * scalar);
}

Math::Vector3D Math::Vector3D::operator/(double const scalar) const
{
    return Math::Vector3D(_x / scalar, _y / scalar, _z / scalar);
}

Math::Vector3D& Math::Vector3D::operator*=(double const scalar)
{
    _x *= scalar;
    _y *= scalar;
    _z *= scalar;
}

Math::Vector3D& Math::Vector3D::operator/=(double const scalar)
{
    _x /= scalar;
    _y /= scalar;
    _z /= scalar;
}

bool Math::Vector3D::operator==(Vector3D const& vector) const
{
    return (
        _x == vector.getX()
            && _y == vector.getY()
            && _z == vector.getZ()
    );
}

bool Math::Vector3D::operator!=(Vector3D const& vector) const
{
    return !(*this == vector);
}
