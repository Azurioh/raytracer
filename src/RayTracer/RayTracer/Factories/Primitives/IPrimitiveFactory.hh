/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IPrimitiveFactory
*/

#pragma once

#include "Math/Point3D/Point3D.hh"
#include "Math/Vector3D/Vector3D.hh"
#include "RayTracer/Primitives/IPrimitive.hh"

#include <memory>

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
                    virtual std::unique_ptr<IPrimitive> createPlane(Math::Point3D origin, Math::Vector3D normal) = 0;
            };
        }
    }
}
