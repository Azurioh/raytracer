/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scene
*/

#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <thread>
#include <tuple>
#include <mutex>

#include "RayTracer/Camera/Camera.hh"
#include "RayTracer/Light/Light.hh"
#include "RayTracer/Primitives/IPrimitive.hh"

using Color = std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>;
using HitPrimitives = std::vector<std::pair<RayTracer::IPrimitive *, std::vector<double>>>;

namespace RayTracer
{
    /**
     * @class Scene
     *
     * @brief Scene class
     */
    class Scene {
        public:
            /**
             * @brief Default constructor of the scene
             */
            Scene();

            enum CameraMovement {
                WINDOW_CLOSED,
                NOTHING,
                FRONT,
                BACK,
                LEFT,
                RIGHT,
                UP,
                DOWN,
                UP_ANGLE,
                DOWN_ANGLE,
                LEFT_ANGLE,
                RIGHT_ANGLE,
            };

            enum ScaleFactor {
                X2,
                X3,
                X4,
            };

            /**
             * @brief Get the Pixels object
             *
             * @return The pixels of the scene
             */
            std::vector<std::vector<Color>> getPixels(void) const;

            /**
             * @brief Set the Pixels object
             *
             * @param pixels The pixels of the scene
             */
            void setPixels(std::vector<std::vector<Color>> pixels);

            /**
             * @brief Move the camera
             *
             * @param movement The movement of the camera
             */
            void moveCamera(CameraMovement movement);

            /**
             * @brief Make the render of the scene
             *
             */
            void makeRender(void);

            /**
             * @brief Export the scene to an output file
             *
             */
            void exportToOutputFile(void);

        private:
            std::unique_ptr<Camera> _camera;
            std::vector<std::unique_ptr<IPrimitive>> _primitives;
            std::vector<std::unique_ptr<Light>> _lights;
            std::vector<std::vector<Color>> _pixels;
            std::mutex _pixelsMutex;
            double _ambientFactor = 0.2;
            double _diffuseFactor = 0;
            std::mutex _lock;

            /**
             * @brief Get the hit primitive
             *
             * @param ray The ray to check
             * @return HitPrimitives The hit primitive
             */
            HitPrimitives _getHitPrimitive(RayTracer::Ray ray);

            /**
             * @brief Get the closest primitive
             *
             * @param ray The ray to check
             * @return std::pair<RayTracer::IPrimitive *, double> The closest primitive
             */
            std::pair<RayTracer::IPrimitive *, double> _getClosestPrimitive(RayTracer::Ray ray);

            /**
             * @brief Get the color of the primitive
             *
             * @param primitive The primitive to check
             * @param determinant The determinant of the primitive
             * @param ray The ray to check
             * @return Color The color of the primitive
             */
            Color _getColor(RayTracer::IPrimitive *primitive, double determinant, RayTracer::Ray ray);

            /**
             * @brief Check if the primitive is in shadow
             *
             * @param primitive The primitive to check
             * @param shadowRay The shadow ray
             * @return true The primitive is in shadow
             * @return false The primitive is not in shadow
             */
            bool _isInShadow(RayTracer::IPrimitive *primitive, RayTracer::Ray shadowRay);

            /**
             * @brief Apply light on the pixel
             *
             * @param primitive The primitive to check
             * @param light The light to apply
             * @return Color The color of the primitive
             */
            Color _applyLightOnPixel(RayTracer::IPrimitive *primitive, double light);

            /**
             * @brief Render the scene
             *
             * @param yStart The start of the y axis
             * @param nbStep The number of steps
             */
            void _renderThreading(std::size_t yStart, std::size_t nbStep);

            /**
             * @brief Get the primitive color
             *
             * @param hitPrimitives The hit primitives
             * @param index The index of the primitive
             * @param ray The ray to check
             * @param depth The depth of the ray
             * @return Color The color of the primitive
             */
            Color _getPrimitiveColor(HitPrimitives hitPrimitives, std::size_t index, RayTracer::Ray ray, std::size_t depth = 0);

            /**
             * @brief Handle the flat color
             *
             * @param hitPrimitives The hit primitives
             * @param index The index of the primitive
             * @param ray The ray to check
             * @return Color The color of the primitive
             */
            Color _handleFlatColor(HitPrimitives hitPrimitives, std::size_t index, RayTracer::Ray ray);

            /**
             * @brief Handle the reflect color
             *
             * @param hitPrimitives The hit primitives
             * @param index The index of the primitive
             * @param ray The ray to check
             * @param depth The depth of the ray
             * @return Color The color of the primitive
             */
            Color _handleReflectColor(HitPrimitives hitPrimitives, std::size_t index, RayTracer::Ray ray, std::size_t depth = 0);

            /**
             * @brief Scale the scene
             *
             * @param factor The factor of the scale
             */
            void _scale(ScaleFactor factor);

            /**
             * @brief Get the around color
             *
             * @param i The i of the pixel
             * @param j The j of the pixel
             * @return std::vector<std::vector<Color>> The around color
             */
            std::vector<std::vector<Color>> _getAroundColor(int i, int j);

            /**
             * @brief Get the scale 2 color
             *
             * @param colors The colors
             * @return std::vector<Color> The scale 2 color
             */
            std::vector<Color> _getScale2Color(std::vector<std::vector<Color>> colors);

            /**
             * @brief Get the scale 3 color
             *
             * @param colors The colors
             * @return std::vector<Color> The scale 3 color
             */
            std::vector<Color> _getScale3Color(std::vector<std::vector<Color>> colors);
    };
}
