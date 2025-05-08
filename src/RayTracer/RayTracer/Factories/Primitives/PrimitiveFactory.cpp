/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PrimitiveFactory
*/

#include "PrimitiveFactory.hh"
#include "RayTracer/Primitives/Sphere/Sphere.hh"
#include "RayTracer/Primitives/Plane/Plane.hh"

RayTracer::Factories::PrimitiveFactory::PrimitiveFactory()
{
    _primitives[SPHERE] = [](){ return std::unique_ptr<RayTracer::IPrimitive>(new RayTracer::Primitives::Sphere()); };
    _primitives[PLANE] = [](){ return std::unique_ptr<RayTracer::IPrimitive>(new RayTracer::Primitives::Plane()); };
}

std::unique_ptr<RayTracer::IPrimitive> RayTracer::Factories::PrimitiveFactory::create(Type type)
{
    return _primitives[type]();
}
