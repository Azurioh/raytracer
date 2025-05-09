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
    /**
     * @class PrimitiveFactory
     *
     * @brief Primitive factory class
     */
    class PrimitiveFactory {
        public:
            /**
             * @brief Default constructor for the PrimitiveFactory object
             */
            PrimitiveFactory();

            /**
             * @brief Default destructor for the PrimitiveFactory object
             */
            ~PrimitiveFactory() = default;

            enum Type {
                SPHERE,
                PLANE
            };

            /**
             * @brief Create a primitive
             *
             * @param type The type of the primitive
             * @return std::unique_ptr<IPrimitive> The created primitive
             */
            std::unique_ptr<IPrimitive> create(Type type);

        private:
            std::map<Type, std::unique_ptr<IPrimitive>(*)()> _primitives;
    };
}
