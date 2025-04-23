/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** GUI
*/

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "RayTracer/Camera/Camera.hh"
#include "RayTracer/Primitives/Sphere/Sphere.hh"

namespace RayTracer
{
    class GUI {
        public:
            GUI(std::vector<RayTracer::Primitives::Sphere> spheres, RayTracer::Camera& camera, sf::VideoMode windowSize = sf::VideoMode(800, 800),
                std::string windowTitle = "SFML Window");
            ~GUI();

            void render(void);
            bool isOpen(void);

        private:
            sf::RenderWindow _window;
            sf::Image _pixelView;
            std::unique_ptr<sf::Texture> _texture;
            std::unique_ptr<sf::Sprite> _sprite;
            std::vector<RayTracer::Primitives::Sphere> _spheres;
            RayTracer::Camera& _cam;

            void _handleEvents(void);
            void _refreshRender(void);
    };
}
