/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** GUI
*/

#include <cstddef>
#include <iostream>
#include "GUI.hh"

RayTracer::GUI::GUI(std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> pixels):
    _window(std::make_unique<sf::RenderWindow>(sf::VideoMode(pixels[0].size(), pixels.size()), "RayTracer GUI")),
    _image(std::make_unique<sf::Image>()), _texture(std::make_unique<sf::Texture>()), _sprite(std::make_unique<sf::Sprite>()), _needRefresh(true)
{
    sf::Color color;

    _image->create(pixels[0].size(), pixels.size());
    for (std::size_t i = 0; i < pixels.size(); i++) {
        for (std::size_t j = 0; j < pixels[i].size(); j++) {
            color.r = std::get<0>(pixels[i][j]);
            color.g = std::get<1>(pixels[i][j]);
            color.b = std::get<2>(pixels[i][j]);
            _image->setPixel(j, i, color);
        }
    }
    _texture->loadFromImage(*_image);
    _sprite->setTexture(*_texture);
}

RayTracer::GUI::~GUI()
{
}

RayTracer::Scene::CameraMovement RayTracer::GUI::render(void)
{
    Scene::CameraMovement movement = _handleEvents();

    _window->clear();
    _window->draw(*_sprite);
    _window->display();
    return movement;
}

bool RayTracer::GUI::isOpen(void) const
{
    return _window->isOpen();
}

bool RayTracer::GUI::isNeedRefresh(void) const
{
    return _needRefresh;
}

void RayTracer::GUI::refresh(std::vector<std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>>> pixels)
{
    sf::Color color;

    for (std::size_t i = 0; i < pixels.size(); i++) {
        for (std::size_t j = 0; j < pixels[i].size(); j++) {
            color.r = std::get<0>(pixels[i][j]);
            color.g = std::get<1>(pixels[i][j]);
            color.b = std::get<2>(pixels[i][j]);
            _image->setPixel(j, i, color);
        }
    }
    _texture->loadFromImage(*_image.get());
    _sprite->setTexture(*_texture.get());
}

RayTracer::Scene::CameraMovement RayTracer::GUI::_handleEvents(void)
{
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
            return Scene::CameraMovement::WINDOW_CLOSED;
        }
        if (event.type != sf::Event::KeyReleased) {
            return Scene::CameraMovement::NOTHING;
        }
        switch (event.key.code) {
            case sf::Keyboard::Z:
                return Scene::CameraMovement::FRONT;
            case sf::Keyboard::S:
                return Scene::CameraMovement::BACK;
            case sf::Keyboard::Q:
                return Scene::CameraMovement::LEFT;
            case sf::Keyboard::D:
                return Scene::CameraMovement::RIGHT;
            case sf::Keyboard::A:
                return Scene::CameraMovement::LEFT_ANGLE;
            case sf::Keyboard::E:
                return Scene::CameraMovement::RIGHT_ANGLE;
            case sf::Keyboard::R:
                return Scene::CameraMovement::UP_ANGLE;
            case sf::Keyboard::F:
                return Scene::CameraMovement::DOWN_ANGLE;
            default:
                return Scene::CameraMovement::NOTHING;
        }
    }
    return Scene::CameraMovement::NOTHING;
}
