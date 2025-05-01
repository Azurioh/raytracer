/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Matrix
*/

#pragma once

#include <vector>

namespace Math
{
    class Vector3D;
    class Matrix {
        public:
            Matrix(std::vector<std::vector<double>> values);
            ~Matrix() = default;

            Vector3D applyMatrixToVector(Vector3D vector);

        private:
            std::vector<std::vector<double>> _values;
    };
}
