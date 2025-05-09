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
    class Scene {
        public:
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

            std::vector<std::vector<Color>> getPixels(void) const;

            void setPixels(std::vector<std::vector<Color>> pixels);

            void moveCamera(CameraMovement movement);
            void makeRender(void);
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

            HitPrimitives _getHitPrimitive(RayTracer::Ray ray);
            std::pair<RayTracer::IPrimitive *, double> _getClosestPrimitive(RayTracer::Ray ray);
            Color _getColor(RayTracer::IPrimitive *primitive, double determinant, RayTracer::Ray ray);
            bool _isInShadow(RayTracer::IPrimitive *primitive, RayTracer::Ray shadowRay);
            Color _applyLightOnPixel(RayTracer::IPrimitive *primitive, double light);
            void _renderThreading(std::size_t yStart, std::size_t nbStep);
            Color _getPrimitiveColor(HitPrimitives hitPrimitives, std::size_t index, RayTracer::Ray ray, std::size_t depth = 0);
            Color _handleFlatColor(HitPrimitives hitPrimitives, std::size_t index, RayTracer::Ray ray);
            Color _handleReflectColor(HitPrimitives hitPrimitives, std::size_t index, RayTracer::Ray ray, std::size_t depth = 0);
            void _scale(ScaleFactor factor);
            std::vector<std::vector<Color>> _getAroundColor(int i, int j);
            std::vector<Color> _getScale2Color(std::vector<std::vector<Color>> colors);
            std::vector<Color> _getScale3Color(std::vector<std::vector<Color>> colors);
    };
}
