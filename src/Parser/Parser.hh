/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Matrix
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <libconfig.h++>

#pragma once

namespace RayTracer{
    class Parser {
        public:
            Parser();
            ~Parser();
            void parseFile(std::string filePath);
            void parseLights(libconfig::Setting& root);
            void parseCameras();

        protected:
        private:
            std::vector<std::tuple<std::tuple<int, int>, std::tuple<int, int, int>, std::tuple<int, int, int>, int>> _camera;
            float _ambient_light;
            float _diffuse_light;
            std::vector<std::tuple<int, int, int>> _points;
            std::vector<std::tuple<int, int, int>> _directionals;
    };
}
