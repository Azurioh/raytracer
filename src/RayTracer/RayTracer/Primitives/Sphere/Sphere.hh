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

namespace RayTracer
{
    namespace Primitives
    {
        class Sphere
        {
            public:
                Sphere(Math::Point3D center, double radius);
                ~Sphere();

                Math::Point3D center;
                double radius;

                std::vector<double> hits(RayTracer::Ray const &ray) const;

            protected:
            private:
        };
    }
}
