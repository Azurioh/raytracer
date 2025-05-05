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
#include <tuple>
#include <thread>
#include <mutex>

#include "RayTracer/Camera/Camera.hh"
#include "RayTracer/Light/Light.hh"
#include "RayTracer/Primitives/IPrimitive.hh"

namespace RayTracer
{
    class Scene {
        public:
            Scene();
            ~Scene();

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

            std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> getPixels(void) const;

            void setPixels(std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> pixels);

            void moveCamera(CameraMovement movement);
            void makeRender(void);
            void exportToOutputFile(void);

        private:
            std::unique_ptr<Camera> _camera;
            std::vector<std::unique_ptr<IPrimitive>> _primitives;
            std::vector<std::unique_ptr<Light>> _lights;
            std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> _pixels;
            double _ambientFactor = 0.2;
            double _diffuseFactor = 0;
            std::mutex _lock;

            std::vector<std::pair<RayTracer::IPrimitive *, std::vector<double>>> _getHitPrimitive(RayTracer::Ray ray);
            std::pair<RayTracer::IPrimitive *, double> _getClosestPrimitive(RayTracer::Ray ray);
            std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> _getColor(RayTracer::IPrimitive *primitive, double determinant, RayTracer::Ray ray);
            bool _isInShadow(RayTracer::IPrimitive *primitive, RayTracer::Ray shadowRay);
            std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> _applyLightOnPixel(RayTracer::IPrimitive *primitive, double light);
            void _renderThreading(std::size_t yStart, std::size_t nbStep);
    };
}
