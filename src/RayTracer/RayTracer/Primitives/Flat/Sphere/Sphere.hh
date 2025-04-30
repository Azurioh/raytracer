/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#pragma once

#include <vector>
#include "Math/Point3D/Point3D.hh"
#include "RayTracer/Ray/Ray.hh"
#include "RayTracer/Primitives/APrimitive.hh"

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

                    std::vector<double> hits(RayTracer::Ray const &ray) const;

                    void setRadius(double radius);

                private:
                    double _radius;
            };
        }
    }
}
