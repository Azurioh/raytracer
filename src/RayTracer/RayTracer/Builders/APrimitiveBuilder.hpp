/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitiveBuilder
*/

#pragma once

#include "IPrimitiveBuilder.hh"

namespace RayTracer::Builders
{
    template <typename T>
    class APrimitiveBuilder : public IPrimitiveBuilder<T> {
        public:
            APrimitiveBuilder() = default;
            ~APrimitiveBuilder() = default;

            /**
             * @brief Get the Primitive object
             *
             * @return T* The primitive
             */
            std::unique_ptr<T>& getPrimitive() { return _primitive; };

        protected:
            std::unique_ptr<T> _primitive;
    };
}
