/*
** EPITECH PROJECT, 2025
** bs-raytracer
** File description:
** Camera
*/

#pragma once

#include <cstddef>
#include "Math/Point3D/Point3D.hh"
#include "RayTracer/Ray/Ray.hh"
#include "Screen/Screen.hh"

namespace RayTracer
{
    /**
     * @class Camera
     *
     * @brief Camera class
     */
    class Camera
    {
        public:
            /**
             * @brief Default constructor for the Camera object
             */
            Camera();

            /**
             * @brief Default destructor for the Camera object
             */
            ~Camera() = default;

            /**
             * @brief Get the origin of the camera
             *
             * @return Math::Point3D The origin of the camera
             */
            Math::Point3D getOrigin(void) const;

            /**
             * @brief Get the screen of the camera
             *
             * @return RayTracer::Screen The screen of the camera
             */
            RayTracer::Screen getScreen(void) const;

            /**
             * @brief Get the screen width of the camera
             *
             * @return double The screen width of the camera
             */
            double getScreenWidth(void) const;

            /**
             * @brief Get the screen height of the camera
             *
             * @return double The screen height of the camera
             */
            double getScreenHeight(void) const;

            /**
             * @brief Set the origin of the camera
             *
             * @param origin The origin of the camera
             */
            void setOrigin(const Math::Point3D& origin);

            /**
             * @brief Set the screen of the camera
             *
             * @param screen The screen of the camera
             */
            void setScreen(const RayTracer::Screen& screen);

            /**
             * @brief Get the ray of the camera
             *
             * @param u The u coordinate of the ray
             * @param v The v coordinate of the ray
             * @return RayTracer::Ray The ray of the camera
             */
            RayTracer::Ray ray(double u, double v);

            /**
             * @brief Move the camera
             *
             * @param movement The movement of the camera
             */
            void moveCamera(Math::Vector3D movement);

        private:
            Math::Point3D _origin;
            RayTracer::Screen _screen;
            double _screenWidth;
            double _screenHeight;
    };
}
