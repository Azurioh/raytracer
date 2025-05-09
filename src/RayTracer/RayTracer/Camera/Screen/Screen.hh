/*
** EPITECH PROJECT, 2025
** bs-raytracer
** File description:
** Screen
*/

#pragma once

#include "Math/Point3D/Point3D.hh"
#include "Math/Vector3D/Vector3D.hh"

namespace RayTracer
{
    /**
     * @class Screen
     *
     * @brief Screen class
     */
    class Screen {
        public:
            /**
             * @brief Default constructor for the Screen object
             */
            Screen();

            /**
             * @brief Constructor for the Screen object
             *
             * @param origin The origin of the screen
             * @param bottomSide The bottom side of the screen
             * @param leftSide The left side of the screen
             */
            Screen(const Math::Point3D& origin, const Math::Vector3D& bottomSide, const Math::Vector3D& leftSide);

            /**
             * @brief Default destructor for the Screen object
             */
            ~Screen();

            /**
             * @brief Get the origin of the screen
             *
             * @return Math::Point3D The origin of the screen
             */
            Math::Point3D getOrigin(void) const;

            /**
             * @brief Get the bottom side of the screen
             *
             * @return const Math::Vector3D& The bottom side of the screen
             */
            const Math::Vector3D& getBottomSide(void) const;

            /**
             * @brief Get the left side of the screen
             *
             * @return const Math::Vector3D& The left side of the screen
             */
            const Math::Vector3D& getLeftSide(void) const;

            /**
             * @brief Set the origin of the screen
             *
             * @param point The origin of the screen
             */
            void setOrigin(const Math::Point3D& point);

            /**
             * @brief Set the bottom side of the screen
             *
             * @param vector The bottom side of the screen
             */
            void setBottomSide(const Math::Vector3D& vector);

            /**
             * @brief Set the left side of the screen
             *
             * @param vector The left side of the screen
             */
            void setLeftSide(const Math::Vector3D& vector);

            /**
             * @brief Get the point at the given coordinates
             *
             * @param u The u coordinate
             * @param v The v coordinate
             * @return Math::Point3D The point at the given coordinates
             */
            Math::Point3D pointAt(double u, double v);

        private:
            Math::Point3D _origin;
            Math::Vector3D _bottomSide;
            Math::Vector3D _leftSide;
    };
}
