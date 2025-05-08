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
        for (int i = 0; i < pointList.getLength(); i++) {
            const libconfig::Setting& light = pointList[i];
            light.lookupValue("x", std::get<0>(vector));
            light.lookupValue("y", std::get<1>(vector));
            light.lookupValue("z", std::get<2>(vector));
            _points.push_back(vector);
        }
    }
    if (lights.exists("directional")) {
        const libconfig::Setting& directionalList = lights["directional"];
        for (int i = 0; i < directionalList.getLength(); i++) {
            const libconfig::Setting& light = directionalList[i];
            light.lookupValue("x", std::get<0>(vector));
            light.lookupValue("y", std::get<1>(vector));
            light.lookupValue("z", std::get<2>(vector));
            _directionals.push_back(vector);
        }
    }
    return;
}

void RayTracer::Parser::parseCameras(libconfig::Setting& root)
{
    const libconfig::Setting& cameras = root["cameras"];
    std::tuple<int, int> resolution;
    std::tuple<int, int, int> position;
    std::tuple<int, int, int> rotation;
    int fov;

    if (cameras.exists("cameras")) {
        const libconfig::Setting& camerasList = cameras["cameras"];
        for (int i = 0; i < camerasList.getLength(); i++) {
            const libconfig::Setting& camera = camerasList[i];

            const libconfig::Setting& res = camera["resolution"];
            res.lookupValue("width", std::get<0>(resolution));
            res.lookupValue("height", std::get<1>(resolution));

            const libconfig::Setting& pos = camera["position"];
            pos.lookupValue("x", std::get<0>(position));
            pos.lookupValue("y", std::get<1>(position));
            pos.lookupValue("z", std::get<2>(position));

            const libconfig::Setting& rot = camera["rotation"];
            rot.lookupValue("x", std::get<0>(rotation));
            rot.lookupValue("y", std::get<1>(rotation));
            rot.lookupValue("z", std::get<2>(rotation));

            camera.lookupValue("fieldOfView", fov);
            _camera.push_back(std::make_tuple(resolution, position, rotation, fov));
        }
    }
    return;
}

void RayTracer::Parser::parseSpheres(libconfig::Setting& primitives)
{
    libconfig::Setting& spheresList = primitives["spheres"];
    std::tuple<int, int, int> position;
    int radius;
    std::tuple<int, int, int> color;

    for (int i = 0; i < spheresList.getLength(); i++) {
        const libconfig::Setting& sphere = spheresList[i];
        sphere.lookupValue("x", std::get<0>(position));
        sphere.lookupValue("y", std::get<1>(position));
        sphere.lookupValue("z", std::get<2>(position));
        sphere.lookupValue("r", radius);
        const libconfig::Setting& col = sphere["color"];
        col.lookupValue("r", std::get<0>(color));
        col.lookupValue("g", std::get<1>(color));
        col.lookupValue("b", std::get<2>(color));
        _spheres.push_back(std::make_tuple(position, radius, color));
    }
    return;
}

void RayTracer::Parser::parsePlanes(libconfig::Setting& primitives)
{
    libconfig::Setting& planesList = primitives["planes"];
    std::string axis;
    int position;
    std::tuple<int, int, int> color;

    for (int i = 0; i < planesList.getLength(); i++) {
        const libconfig::Setting& plane = planesList[i];
        plane.lookupValue("axis", axis);
        plane.lookupValue("position", position);
        const libconfig::Setting& col = plane["color"];
        col.lookupValue("r", std::get<0>(color));
        col.lookupValue("g", std::get<1>(color));
        col.lookupValue("b", std::get<2>(color));
        _planes.push_back(std::make_tuple(axis, position, color));
    }
    return;
}

void RayTracer::Parser::parsePrimitives(libconfig::Setting& root)
{
    libconfig::Setting& primitives = root["primitives"];

    if (primitives.exists("spheres")){
        parseSpheres(primitives);
    }
    if (primitives.exists("planes")){
        parsePlanes(primitives);
    }
    return;
}

void RayTracer::Parser::parseFile(std::string filePath)
{
    std::string folderPath = "Scenes/";
    filePath = folderPath + filePath;
    libconfig::Config cfg;
    cfg.readFile(filePath);
    libconfig::Setting& root = cfg.getRoot();

    parseCameras(root);
    parsePrimitives(root);
    parseLights(root);
    return;
}
