/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** FlatFactory
*/

#include <map>
#include <memory>

#include "Math/Point3D/Point3D.hh"
#include "RayTracer/Factories/Primitives/IPrimitiveFactory.hh"
#include "RayTracer/Primitives/IPrimitive.hh"

#pragma once

namespace RayTracer
{
    namespace Factories
    {
        namespace Primitive
        {
            class FlatFactory : public IPrimitiveFactory {
                public:
                    FlatFactory() = default;
                    ~FlatFactory() = default;

                    std::unique_ptr<IPrimitive> createSphere(Math::Point3D origin, double radius);
            };
        }
    }
}
