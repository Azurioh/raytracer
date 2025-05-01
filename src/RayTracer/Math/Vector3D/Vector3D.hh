/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Vector3D
*/

#pragma once

namespace Math {
    class Point3D;
    class Vector3D {
        public:
            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(const Point3D &point);
            Vector3D(const Vector3D &vector);
            ~Vector3D() = default;

            double getX(void) const;
            double getY(void) const;
            double getZ(void) const;

            void setX(double x);
            void setY(double x);
            void setZ(double x);

            void rotateX(double angle);
            void rotateY(double angle);

            double length(void) const;
            double dot(Vector3D const& vector) const;
            void normalize(void);

            Vector3D operator+(Vector3D const& vector) const;
            Vector3D operator-(Vector3D const& vector) const;
            Vector3D& operator+=(Vector3D const& vector);
            Vector3D& operator-=(Vector3D const& vector);
            Vector3D& operator=(Vector3D const& vector);

            Vector3D operator*(double const scalar) const;
            Vector3D operator/(double const scalar) const;
            Vector3D& operator*=(double const scalar);
            Vector3D& operator/=(double const scalar);

            bool operator==(Vector3D const& vector) const;
            bool operator!=(Vector3D const& vector) const;

        private:
            double _x;
            double _y;
            double _z;
    };
}

