/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** GUI
*/

#pragma once

#include <cstdint>
#include <memory>
#include <tuple>
#include <SFML/Graphics.hpp>
#include "RayTracer/Scene/Scene.hh"

namespace RayTracer
{
    class GUI {
        public:
            GUI(std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> pixels);
            ~GUI();

            Scene::CameraMovement render(void);
            bool isOpen(void) const;
            bool isNeedRefresh(void) const;

            void refresh(std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> pixels);

        private:
            std::unique_ptr<sf::RenderWindow> _window;
            std::unique_ptr<sf::Image> _image;
            std::unique_ptr<sf::Texture> _texture;
            std::unique_ptr<sf::Sprite> _sprite;
            bool _needRefresh;

            Scene::CameraMovement _handleEvents(void);
    };
}
