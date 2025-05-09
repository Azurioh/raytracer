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
    /**
     * @class Light
     *
     * @brief Light class
     */
    class Light {
        public:
            enum Color {
                RED,
                GREEN,
                BLUE,
                WHITE,
                TRANSPARENT,
            };

            /**
             * @brief Construct a new Light object
             *
             * @param direction The direction of the light
             * @param intensity The intensity of the light
             * @param color The color of the light
             */
            Light(Math::Vector3D direction, double _intensity = 1, Color color = TRANSPARENT);

            /**
             * @brief Destroy the Light object
             */
            ~Light();

            /**
             * @brief Get the direction of the light
             *
             * @return Math::Vector3D The direction of the light
             */
            Math::Vector3D getDirection(void) const;

            /**
             * @brief Get the intensity of the light
             *
             * @return double The intensity of the light
             */
            double getIntensity(void) const;

            /**
             * @brief Get the color of the light
             *
             * @return Color The color of the light
             */
            Color getColor(void) const;

            /**
             * @brief Set the direction of the light
             *
             * @param direction The direction of the light
             */
            void setDirection(Math::Vector3D direction);

            /**
             * @brief Set the intensity of the light
             *
             * @param intensity The intensity of the light
             */
            void setIntensity(double intensity);

            /**
             * @brief Set the color of the light
             *
             * @param color The color of the light
             */
            void setColor(Color color);

        private:
            Math::Vector3D _direction;
            double _intensity;
            Color _color;
    };
}
