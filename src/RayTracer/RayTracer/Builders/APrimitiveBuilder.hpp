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
    /**
     * @class APrimitiveBuilder
     *
     * @brief Abstract class for primitive builders
     *
     * @tparam T The type of the primitive to build
     */
    class APrimitiveBuilder : public IPrimitiveBuilder<T> {
        public:
            /**
             * @brief Default constructor for the APrimitiveBuilder class
             */
            APrimitiveBuilder() = default;

            /**
             * @brief Default destructor for the APrimitiveBuilder class
             */
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
