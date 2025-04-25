/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** GUI
*/

#pragma once

#include <condition_variable>
#include <mutex>
#include <memory>
#include <thread>
#include <SFML/Graphics.hpp>
#include "RayTracer/Camera/Camera.hh"
#include "RayTracer/Primitives/Sphere/Sphere.hh"

namespace RayTracer
{
    class GUI {
        public:
            GUI(std::vector<RayTracer::Primitives::Sphere> spheres, RayTracer::Camera& camera, sf::Image& pixelView,
                std::string windowTitle = "SFML Window", std::size_t nbThreads = 1);
            ~GUI();

            void render(void);
            bool isOpen(void);

        private:
            sf::RenderWindow _window;
            sf::Image& _pixelView;
            std::unique_ptr<sf::Texture> _texture;
            std::unique_ptr<sf::Sprite> _sprite;
            std::vector<RayTracer::Primitives::Sphere> _spheres;
            RayTracer::Camera& _cam;
            std::vector<std::thread> _threads;
            std::vector<bool> _renderComplete;
            std::mutex _pixelMutex;
            std::mutex _camMutex;
            std::condition_variable _camCv;
            std::atomic<bool> _camChanged{false};

            void _handleEvents(void);
            void _refreshRender(std::size_t yStart, std::size_t nbStep, std::size_t threadIndex);
            bool _renderIsFinished(void);
    };
}
