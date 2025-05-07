/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Main.cpp
*/

#include "RayTracer/Core/Core.hh"
#include "../Parser/Parser.hh"

#include <cstdint>

std::int32_t main(int ac, char **av)
{
    RayTracer::Core core;
    RayTracer::Parser parser;

    (void)ac;
    parser.parseFile(av[1]);
    core.start();
    return 0;
}
