/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Light
*/

#pragma once

#include "Math/Vector3D/Vector3D.hh"

namespace RayTracer
{
    class Light {
        public:
            enum Color {
                RED,
                GREEN,
                BLUE,
                WHITE,
                TRANSPARENT,
            };

            Light(Math::Vector3D direction, double _intensity = 1, Color color = TRANSPARENT);
            ~Light();

            Math::Vector3D getDirection(void) const;
            double getIntensity(void) const;
            Color getColor(void) const;

            void setDirection(Math::Vector3D direction);
            void setIntensity(double intensity);
            void setColor(Color color);

        private:
            Math::Vector3D _direction;
            double _intensity;
            Color _color;
    };
}
