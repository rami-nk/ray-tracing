cmake_minimum_required(VERSION 3.25)
project(ray_tracing)

set(CMAKE_CXX_STANDARD 23)

find_package(glfw3 3.3 REQUIRED)

add_subdirectory(metal-cpp-cmake/metal-cmake)

add_executable(ray_tracing main.cpp)

target_link_libraries(ray_tracing glfw METAL_CPP)