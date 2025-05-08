/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PrimitiveFactory
*/

#pragma once

#include <map>
#include <memory>
#include "RayTracer/Primitives/IPrimitive.hh"

namespace RayTracer::Factories
{
    class PrimitiveFactory {
        public:
            PrimitiveFactory();
            ~PrimitiveFactory() = default;

            enum Type {
                SPHERE,
                PLANE
            };

            std::unique_ptr<IPrimitive> create(Type type);

        private:
            std::map<Type, std::unique_ptr<IPrimitive>(*)()> _primitives;
    };
}
