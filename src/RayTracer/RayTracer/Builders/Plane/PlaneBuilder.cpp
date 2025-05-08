/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PlaneBuilder
*/

#include "PlaneBuilder.hh"
#include "RayTracer/Error/Error.hh"
#include "RayTracer/Factories/Primitives/PrimitiveFactory.hh"

RayTracer::Builders::PlaneBuilder::PlaneBuilder()
{
    reset();
}

RayTracer::Builders::PlaneBuilder::~PlaneBuilder()
{
}

void RayTracer::Builders::PlaneBuilder::reset()
{
    Factories::PrimitiveFactory factory;
    std::unique_ptr<IPrimitive> primitive = factory.create(Factories::PrimitiveFactory::PLANE);
    Primitives::Plane *plane = dynamic_cast<Primitives::Plane *>(primitive.get());

    if (!plane) {
        throw Errors::Builders::InvalidTypeConversion("Cannot cast this primitive into a plane");
    }

    _primitive = std::unique_ptr<Primitives::Plane>(static_cast<Primitives::Plane *>(primitive.release()));
}

void RayTracer::Builders::PlaneBuilder::buildCenter(Math::Point3D const& center)
{
    _primitive->setCenter(center);
}

void RayTracer::Builders::PlaneBuilder::buildRotation(Math::Vector3D const& rotation)
{
    _primitive->setRotation(rotation);
}

void RayTracer::Builders::PlaneBuilder::buildColor(Color color)
{
    _primitive->setColor(color);
}

void RayTracer::Builders::PlaneBuilder::buildSize(std::va_list& args)
{
    double x;
    double y;
    double z;

    x = va_arg(args, double);
    y = va_arg(args, double);
    z = va_arg(args, double);
    _primitive->setNormal(Math::Vector3D(x, y, z));
}

void RayTracer::Builders::PlaneBuilder::buildReflection(double intensity)
{
    _primitive->setHavingReflection(true);
    _primitive->setReflectionIntensity(intensity);
}

void RayTracer::Builders::PlaneBuilder::buildRefraction(double intensity)
{
    _primitive->setHavingRefraction(true);
    _primitive->setRefractionIntensity(intensity);
}
