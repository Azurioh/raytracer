/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Error
*/

#include "Error.hh"

RayTracer::Error::Error(std::string msg): _msg(msg)
{
}

const char *RayTracer::Error::what() const noexcept
{
    return _msg.c_str();
}

RayTracer::Errors::Builders::InvalidTypeConversion::InvalidTypeConversion(std::string msg): Error(msg)
{
}
