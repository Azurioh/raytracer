/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Error
*/

#pragma once

#include <exception>
#include <string>

namespace RayTracer
{
    /**
     * @class Error
     *
     * @brief Error class
     */
    class Error : public std::exception {
        public:
            Error(std::string msg);
            ~Error() = default;

            const char *what() const noexcept;

        private:
            std::string _msg;
    };

    namespace Errors
    {
        namespace Builders
        {
            /**
             * @class InvalidTypeConversion
             *
             * @brief Invalid type conversion error
             */
            class InvalidTypeConversion : public Error {
                public:
                    InvalidTypeConversion(std::string msg);
                    ~InvalidTypeConversion() = default;
            };
        }
    }
}
