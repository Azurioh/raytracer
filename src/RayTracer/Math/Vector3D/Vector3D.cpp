/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Vector3D
*/

#include <cmath>
#include <numbers>
#include <iostream>
#include "Vector3D.hh"
#include "Math/Matrix/Matrix.hh"
#include "Math/Point3D/Point3D.hh"

Math::Vector3D::Vector3D(): _x(0.0), _y(0.0), _z(0.0)
{
}

Math::Vector3D::Vector3D(double x, double y, double z): _x(x), _y(y), _z(z)
{
}

Math::Vector3D::Vector3D(const Point3D &point)
{
    _x = point.getX();
    _y = point.getY();
    _z = point.getZ();
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

void Math::Vector3D::setX(double x)
{
    _x = x;
}

void Math::Vector3D::setY(double y)
{
    _y = y;
}

void Math::Vector3D::setZ(double z)
{
    _z = z;
}

void Math::Vector3D::rotateX(double angle)
{
    double radian = angle * (std::numbers::pi / 180);
    Math::Matrix rotationMatrix({
        {1, 0, 0},
        {0, std::cos(radian), -std::sin(radian)},
        {0, std::sin(radian),  std::cos(radian)}
    });
    Math::Vector3D newDirection = rotationMatrix.applyMatrixToVector(*this);

    _x = newDirection.getX();
    _y = newDirection.getY();
    _z = newDirection.getZ();
}

void Math::Vector3D::rotateY(double angle)
{
    double radian = angle * (std::numbers::pi / 180.0);
    Math::Matrix rotationMatrix({
        { std::cos(radian), 0, std::sin(radian)},
        { 0, 1, 0 },
        { -std::sin(radian), 0, std::cos(radian)}
    });
    Math::Vector3D newDirection = rotationMatrix.applyMatrixToVector(*this);

    _x = newDirection.getX();
    _y = newDirection.getY();
    _z = newDirection.getZ();
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

void Math::Vector3D::normalize(void)
{
    *this /= length();
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
    return *this;
}

Math::Vector3D& Math::Vector3D::operator-=(Vector3D const& vector)
{
    _x -= vector.getX();
    _y -= vector.getY();
    _z -= vector.getZ();
    return *this;
}

Math::Vector3D& Math::Vector3D::operator=(Vector3D const& vector)
{
    _x = vector.getX();
    _y = vector.getY();
    _z = vector.getZ();
    return *this;
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
    return *this;
}

Math::Vector3D& Math::Vector3D::operator/=(double const scalar)
{
    _x /= scalar;
    _y /= scalar;
    _z /= scalar;
    return *this;
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

