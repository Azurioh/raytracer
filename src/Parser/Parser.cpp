/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Parser
*/

#include "Parser.hh"

RayTracer::Parser::Parser()
{
}

RayTracer::Parser::~Parser()
{
}

void RayTracer::Parser::parseLights(libconfig::Setting& root)
{
    const libconfig::Setting& lights = root["lights"];
    lights.lookupValue("ambient", _ambient_light);
    lights.lookupValue("diffuse", _diffuse_light);
    std::tuple<int, int, int> vector;

    if (lights.exists("point")) {
        const libconfig::Setting& pointList = lights["point"];
        for (int i = 0; i < pointList.getLength(); ++i) {
            const libconfig::Setting& light = pointList[i];
            light.lookupValue("x", std::get<0>(vector));
            light.lookupValue("y", std::get<1>(vector));
            light.lookupValue("z", std::get<2>(vector));
            _points.push_back(vector);
        }
    }
    if (lights.exists("directional")) {
        const libconfig::Setting& directionalList = lights["directional"];
        for (int i = 0; i < directionalList.getLength(); ++i) {
            const libconfig::Setting& light = directionalList[i];
            light.lookupValue("x", std::get<0>(vector));
            light.lookupValue("y", std::get<1>(vector));
            light.lookupValue("z", std::get<2>(vector));
            _directionals.push_back(vector);
        }
    }

}

void RayTracer::Parser::parseCameras()
{

}

void RayTracer::Parser::parseFile(std::string filePath)
{
    std::string folderPath = "Scenes/";
    filePath = folderPath + filePath;
    libconfig::Config cfg;
    cfg.readFile(filePath);
    libconfig::Setting& root = cfg.getRoot();

    parseLights(root);
    // std::cout << "ambient light " << _ambient_light << std::endl;
    // std::cout << "diffuse_light " << _diffuse_light << std::endl << std::endl;
    // std::cout << "light points" << std::endl;
    // for (auto i : _points){
    //     std::cout << std::get<0>(i) << " " << std::get<1>(i) << " " << std::get<2>(i) << std::endl;
    // }
    // std::cout << std::endl << "directionals lights" << std::endl;
    // for (auto i : _directionals){
    //     std::cout << std::get<0>(i) << " " << std::get<1>(i) << " " << std::get<2>(i) << std::endl;
    // }
}
