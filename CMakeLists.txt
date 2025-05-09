include(FetchContent)
cmake_minimum_required(VERSION 3.27.4)
project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

file(GLOB_RECURSE RAYTRACER_SRC CONFIGURE_DEPENDS src/RayTracer/*.cpp)

include_directories(src/RayTracer)

add_executable(raytracer ${RAYTRACER_SRC})

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2.6.2
)

FetchContent_MakeAvailable(SFML)
target_link_libraries(raytracer sfml-system sfml-window sfml-graphics)
