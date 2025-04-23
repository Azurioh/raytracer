/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Point3D
*/

#pragma once

#include "Math/Vector3D/Vector3D.hh"

namespace Math {
    class Point3D {
        public:
            Point3D() = default;
            Point3D(double x, double y, double z);
            Point3D(const Vector3D &point);
            Point3D(const Point3D &point);
            ~Point3D() = default;

            double getX(void) const;
            double getY(void) const;
            double getZ(void) const;

            void setX(double x);
            void setY(double x);
            void setZ(double x);

            Point3D operator+(const Vector3D& vector) const;
            Point3D& operator+=(const Vector3D& vector);
            Point3D& operator=(const Point3D& point);

            Vector3D operator-(const Point3D& point) const;

            bool operator==(const Point3D& point) const;
            bool operator!=(const Point3D& point) const;

        private:
            double _x;
            double _y;
            double _z;
    };
}
