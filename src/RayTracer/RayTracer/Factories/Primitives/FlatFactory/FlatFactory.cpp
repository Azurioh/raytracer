/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** FlatFactory
*/

#include "FlatFactory.hh"
#include "RayTracer/Primitives/Flat/Sphere/Sphere.hh"

std::unique_ptr<RayTracer::IPrimitive> RayTracer::Factories::Primitive::FlatFactory::createSphere(Math::Point3D origin, double radius)
{
    return std::make_unique<RayTracer::Primitives::Flat::Sphere>(origin, radius);
}
