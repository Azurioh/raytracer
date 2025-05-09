/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Point3D
*/

#pragma once

#include "Math/Vector3D/Vector3D.hh"

namespace Math {
    /**
     * @class Point3D
     *
     * @brief A class that represent a point in a 3D space
     */
    class Point3D {
        public:
            /**
             * @brief Default constructor for the Point3D class
             */
            Point3D();

            /**
             * @brief Constructor with coords for the Point3D class
             *
             * @param x X position value
             * @param y Y position value
             * @param z Z position value
             */
            Point3D(double x, double y, double z);

            /**
             * @brief Copy constructor from Vector3D class
             *
             * @param point The vector
             */
            Point3D(const Vector3D &point);

            /**
             * @brief Copy constructor from Point3D class
             *
             * @param point The point
             */
            Point3D(const Point3D &point);

            /**
             * @brief Default destructor for the Point3D class
             */
            ~Point3D() = default;

            /**
             * @brief Get the x value of the point
             *
             * @return double - The x position
             */
            double getX(void) const;

            /**
             * @brief Get the y value of the point
             *
             * @return double - The y position
             */
            double getY(void) const;

            /**
             * @brief Get the z value of the point
             *
             * @return The z position
             */
            double getZ(void) const;

            /**
             * @brief Set the x value of the point
             *
             * @param x The x value
             */
            void setX(double x);

            /**
             * @brief Set the y value of the point
             *
             * @param y The y value
             */
            void setY(double x);

            /**
             * @brief Set the z value of the point
             *
             * @param z The z value
             */
            void setZ(double x);

            /**
             * @brief Add a vector to the point
             *
             * @param vector The vector to add
             * @return The new point
             */
            Point3D operator+(const Vector3D& vector) const;

            /**
             * @brief Add a vector from the current point instance
             *
             * @param vector The vector to subtract
             * @return The new point
             */
            Point3D& operator+=(const Vector3D& vector);

            /**
             * @brief Assign a point to the current point instance
             *
             * @param point The point to assign
             * @return The current point instance
             */
            Point3D& operator=(const Point3D& point);

           /**
            * @brief Substract a vector from the point
            *
            * @param point The point to substract
            * @return The new vector
            */
            Vector3D operator-(const Point3D& point) const;

            /**
             * @brief Check if the current point instance is equal to another point
             *
             * @param point The point to compare
             * @return true if the points are equal, false otherwise
             */
            bool operator==(const Point3D& point) const;

            /**
             * @brief Check if the current point instance is not equal to another point
             *
             * @param point The point to compare
             * @return true if the points are not equal, false otherwise
             */
            bool operator!=(const Point3D& point) const;

        private:
            double _x;
            double _y;
            double _z;
    };
}
