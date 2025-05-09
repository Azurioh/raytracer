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

    /**
     * @class Matrix
     *
     * @brief A class that used to keep a matrix and multiply it with vectors
     */
    class Matrix {
        public:
            /**
             * @brief Constructor for matrix class with matrix values
             *
             * @param values A double array representing matrix values
             */
            Matrix(std::vector<std::vector<double>> values);

            /**
             * @brief Default destructor for the matrix class.
             */
            ~Matrix() = default;

            /**
             * @brief Multiply a vector with a Matrix
             *
             * @param vector The vector that you want to multiply
             * @return The result of the multiplication
             */
            Vector3D applyMatrixToVector(Vector3D vector);

        private:
            std::vector<std::vector<double>> _values;
    };
}
