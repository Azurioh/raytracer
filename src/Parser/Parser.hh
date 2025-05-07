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
            void parseCameras(libconfig::Setting& root);

        protected:
        private:
            std::vector<std::tuple<std::tuple<double, double>, std::tuple<double, double, double>, std::tuple<double, double, double>, double>> _camera;
            double _ambient_light;
            double _diffuse_light;
            std::vector<std::tuple<double, double, double>> _points;
            std::vector<std::tuple<double, double, double>> _directionals;
    };
}
