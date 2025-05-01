/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Matrix
*/

#include <iostream>
#include "Matrix.hh"
#include "Math/Vector3D/Vector3D.hh"

Math::Matrix::Matrix(std::vector<std::vector<double>> values): _values(values)
{
}

Math::Vector3D Math::Matrix::applyMatrixToVector(Math::Vector3D vector)
{
    double x = _values[0][0] * vector.getX() + _values[0][1] * vector.getY() + _values[0][2] * vector.getZ();
    double y = _values[1][0] * vector.getX() + _values[1][1] * vector.getY() + _values[1][2] * vector.getZ();
    double z = _values[2][0] * vector.getX() + _values[2][1] * vector.getY() + _values[2][2] * vector.getZ();

    return Math::Vector3D(x, y, z);
}

