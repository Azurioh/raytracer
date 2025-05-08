/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** SphereBuilder
*/

#include <iostream>
#include "SphereBuilder.hh"
#include "RayTracer/Error/Error.hh"
#include "RayTracer/Factories/Primitives/PrimitiveFactory.hh"

RayTracer::Builders::SphereBuilder::SphereBuilder()
{
    reset();
}

RayTracer::Builders::SphereBuilder::~SphereBuilder()
{
}

void RayTracer::Builders::SphereBuilder::reset()
{
    Factories::PrimitiveFactory factory;
    std::unique_ptr<IPrimitive> primitive = factory.create(Factories::PrimitiveFactory::Type::SPHERE);
    Primitives::Sphere *sphere = dynamic_cast<Primitives::Sphere *>(primitive.get());

    if (!sphere) {
        throw Errors::Builders::InvalidTypeConversion("Cannot cast this primitive into a sphere");
    }

    _primitive = std::unique_ptr<Primitives::Sphere>(static_cast<Primitives::Sphere *>(primitive.release()));
}

void RayTracer::Builders::SphereBuilder::buildCenter(Math::Point3D const& center)
{
    _primitive->setCenter(center);
}

void RayTracer::Builders::SphereBuilder::buildRotation(Math::Vector3D const& rotation)
{
    _primitive->setRotation(rotation);
}

void RayTracer::Builders::SphereBuilder::buildColor(Color color)
{
    _primitive->setColor(color);
}

void RayTracer::Builders::SphereBuilder::buildSize(std::va_list& args)
{
    double radius = va_arg(args, double);

    _primitive->setRadius(radius);
}

void RayTracer::Builders::SphereBuilder::buildReflection(double intensity)
{
    _primitive->setHavingReflection(true);
    _primitive->setReflectionIntensity(intensity);
}

void RayTracer::Builders::SphereBuilder::buildRefraction(double intensity)
{
    _primitive->setHavingRefraction(true);
    _primitive->setRefractionIntensity(intensity);
}
