/*
** EPITECH PROJECT, 2025
** bs-raytracer
** File description:
** Rectangle3D
*/

#pragma once

#include "Math/Point3D/Point3D.hh"
#include "Math/Vector3D/Vector3D.hh"

namespace RayTracer
{
    class Screen {
        public:
            Screen();
            Screen(const Math::Point3D& origin, const Math::Vector3D& bottomSide, const Math::Vector3D& leftSide);
            ~Screen();

            Math::Point3D getOrigin(void) const;
            Math::Vector3D getBottomSide(void) const;
            Math::Vector3D getLeftSide(void) const;

            void setOrigin(const Math::Point3D& point);
            void setBottomSide(const Math::Vector3D& vector);
            void setLeftSide(const Math::Vector3D& vector);

            Math::Point3D pointAt(double u, double v);

        private:
            Math::Point3D _origin;
            Math::Vector3D _bottomSide;
            Math::Vector3D _leftSide;
    };
}
