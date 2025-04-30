/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IPrimitiveFactory
*/

#pragma once

#include <memory>

#include "Math/Point3D/Point3D.hh"
#include "RayTracer/Primitives/IPrimitive.hh"

namespace RayTracer
{
    namespace Factories
    {
        namespace Primitive
        {
            class IPrimitiveFactory {
                public:
                    IPrimitiveFactory() = default;
                    virtual ~IPrimitiveFactory() = default;

                    virtual std::unique_ptr<IPrimitive> createSphere(Math::Point3D origin, double radius) = 0;
            };
        }
    }
}
