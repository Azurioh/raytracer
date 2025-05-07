/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** FlatFactory
*/

#pragma once

#include "RayTracer/Factories/Primitives/IPrimitiveFactory.hh"
#include "RayTracer/Primitives/IPrimitive.hh"
#include "Math/Vector3D/Vector3D.hh"
#include "Math/Point3D/Point3D.hh"

#include <memory>

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
                    std::unique_ptr<IPrimitive> createPlane(Math::Point3D origin, Math::Vector3D normal);
            };
        }
    }
}
