/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Vector3D
*/

#pragma once

namespace Math {
    class Point3D;

    /**
     * @class Vector3D
     *
     * @brief A class that represent a vector in a 3D space
     */
    class Vector3D {
        public:
            /**
             * @brief Default constructor for the Vector3D class
             */
            Vector3D();

            /**
             * @brief Constructor with coords for the Vector3D class
             *
             * @param x X position value
             * @param y Y position value
             * @param z Z position value
             */
            Vector3D(double x, double y, double z);

            /**
             * @brief Copy constructor from Point3D class
             *
             * @param point The point
             */
            Vector3D(const Point3D &point);

            /**
             * @brief Copy constructor from Vector3D class
             *
             * @param vector The vector
             */
            Vector3D(const Vector3D &vector);

            /**
             * @brief Default destructor for the Vector3D class
             */
            ~Vector3D() = default;

            /**
             * @brief Get the x value of the vector
             *
             * @return The x position
             */
            double getX(void) const;

            /**
             * @brief Get the y value of the vector
             *
             * @return The y position
             */
            double getY(void) const;

            /**
             * @brief Get the z value of the vector
             *
             * @return The z position
             */
            double getZ(void) const;

            /**
             * @brief Set the x value of the vector
             *
             * @param x The x value
             */
            void setX(double x);

            /**
             * @brief Set the y value of the vector
             *
             * @param y The y value
             */
            void setY(double x);

            /**
             * @brief Set the z value of the vector
             *
             * @param z The z value
             */
            void setZ(double x);

            /**
             * @brief Rotate the vector around the Z axis
             *
             * @param angle The angle to rotate
             */
            void rotateX(double angle);

            /**
             * @brief Rotate the vector around the Y axis
             *
             * @param angle The angle to rotate
             */
            void rotateY(double angle);

            /**
             * @brief Get the length of the vector
             *
             * @return The length of the vector
             */
            double length(void) const;

            /**
             * @brief Get the cross product of the vector with another vector
             *
             * @param vector The vector to cross with
             * @return The cross product
             */
            double dot(Vector3D const& vector) const;

            /**
             * @brief Normalize the vector
             *
             * @return The normalized vector
             */
            void normalize(void);

            /**
             * @brief Add a vector to the vector
             *
             * @param vector The vector to add
             * @return The new vector
             */
            Vector3D operator+(Vector3D const& vector) const;

            /**
             * @brief Substract a vector from the vector
             *
             * @param vector The vector to substract
             * @return The new vector
             */
            Vector3D operator-(Vector3D const& vector) const;

            /**
             * @brief Add a vector from the current vector instance
             *
             * @param vector The vector to add
             * @return The current vector instance
             */
            Vector3D& operator+=(Vector3D const& vector);

            /**
             * @brief Substract a vector from the current vector instance
             *
             * @param vector The vector to substract
             * @return The current vector instance
             */
            Vector3D& operator-=(Vector3D const& vector);

            /**
             * @brief Assign a vector to the current vector instance
             *
             * @param vector The vector to assign
             * @return The current vector instance
             */
            Vector3D& operator=(Vector3D const& vector);

            /**
             * @brief Multiply the vector by a scalar
             *
             * @param scalar The scalar to multiply
             * @return The new vector
             */
            Vector3D operator*(double const scalar) const;

            /**
             * @brief Divide the vector by a scalar
             *
             * @param scalar The scalar to divide
             * @return The new vector
             */
            Vector3D operator/(double const scalar) const;

            /**
             * @brief Multiply the vector by a scalar
             *
             * @param scalar The scalar to multiply
             */
            Vector3D& operator*=(double const scalar);

            /**
             * @brief Divide the vector by a scalar
             *
             * @param scalar The scalar to divide
             * @return The new vector
             */
            Vector3D& operator/=(double const scalar);

            /**
             * @brief Compare two vectors
             *
             * @param vector The vector to compare
             * @return true If the vectors are equal, false otherwise
             */
            bool operator==(Vector3D const& vector) const;

            /**
             * @brief Compare two vectors
             *
             * @param vector The vector to compare
             * @return true If the vectors are not equal, false otherwise
             */
            bool operator!=(Vector3D const& vector) const;

        private:
            double _x;
            double _y;
            double _z;
    };
}

