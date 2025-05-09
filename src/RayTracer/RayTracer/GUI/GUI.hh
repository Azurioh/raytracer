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
    /**
     * @class GUI
     *
     * @brief GUI class
     */
    class GUI {
        public:
            /**
             * @brief Construct a new GUI object
             *
             * @param pixels The pixels to display
             */
            GUI(std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> pixels);

            /**
             * @brief Destroy the GUI object
             */
            ~GUI();

            /**
             * @brief Render the GUI
             *
             * @return Scene::CameraMovement The camera movement
             */
            Scene::CameraMovement render(void);

            /**
             * @brief Check if the window is open
             *
             * @return true The window is open
             * @return false The window is closed
             */
            bool isOpen(void) const;

            /**
             * @brief Check if the GUI needs to be refreshed
             *
             * @return true The GUI needs to be refreshed
             * @return false The GUI does not need to be refreshed
             */
            bool isNeedRefresh(void) const;

            /**
             * @brief Refresh the GUI
             *
             * @param pixels The pixels to display
             */
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
