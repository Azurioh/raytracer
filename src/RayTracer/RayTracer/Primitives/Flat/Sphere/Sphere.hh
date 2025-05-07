/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#pragma once

#include "RayTracer/Primitives/APrimitive.hh"
#include "Math/Vector3D/Vector3D.hh"
#include "Math/Point3D/Point3D.hh"
#include "RayTracer/Ray/Ray.hh"

#include <vector>

namespace RayTracer
{
    namespace Primitives
    {
        namespace Flat
        {
            class Sphere : public APrimitive
            {
                public:
                    Sphere(Math::Point3D center = Math::Point3D(0, 0, 0), double radius = 0);
                    ~Sphere();

                    RayTracer::Ray getReflectionVector(RayTracer::Ray const& ray) const override;
                    std::vector<double> hits(RayTracer::Ray const &ray) const override;
                    Math::Vector3D getNormalAt(const Math::Point3D& hitPoint) const override;

                    void setRadius(double radius);

                private:
                    double _radius;
            };
        }
    }
}
