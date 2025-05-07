/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** FlatFactory
*/

#include "RayTracer/Primitives/Flat/Plane/Plane.hpp"
#include "RayTracer/Primitives/Flat/Sphere/Sphere.hh"
#include "RayTracer/Primitives/IPrimitive.hh"
#include "Math/Vector3D/Vector3D.hh"
#include "Math/Point3D/Point3D.hh"
#include "FlatFactory.hh"

#include <memory>

std::unique_ptr<RayTracer::IPrimitive> RayTracer::Factories::Primitive::FlatFactory::createSphere(Math::Point3D origin, double radius)
{
    return std::make_unique<RayTracer::Primitives::Flat::Sphere>(origin, radius);
}

std::unique_ptr<RayTracer::IPrimitive> RayTracer::Factories::Primitive::FlatFactory::createPlane(Math::Point3D origin, Math::Vector3D normal)
{
    return std::make_unique<RayTracer::Primitives::Flat::Plane>(origin, normal);
}
