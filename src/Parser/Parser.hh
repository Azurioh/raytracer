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

using Vector = std::tuple<double, double, double>;

namespace RayTracer{
    class Parser {
        public:
            Parser();
            ~Parser();
            void parseFile(std::string filePath);
            void parseCameras(libconfig::Setting& root);
            void parsePrimitives(libconfig::Setting& root);
            void parseSpheres(libconfig::Setting& primitives);
            void parsePlanes(libconfig::Setting& primitives);
            void parseLights(libconfig::Setting& root);

        protected:
        private:
            std::vector<std::tuple<std::tuple<double, double>, Vector, Vector, double>> _camera;
            std::vector<std::tuple<Vector, double, Vector>> _spheres;
            std::vector<std::tuple<std::string, double, Vector>> _planes;
            double _ambient_light;
            double _diffuse_light;
            std::vector<Vector> _points;
            std::vector<Vector> _directionals;
    };
}
