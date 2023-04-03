cmake_minimum_required(VERSION 3.25)
project(ray_tracing)

set(CMAKE_CXX_STANDARD 23)

find_package(GLEW 2.0 REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

add_executable(ray_tracing main.cpp VertexArray.cpp VertexArray.h VertexBufferLayout.cpp VertexBufferLayout.h LayoutElement.h VertexBuffer.cpp VertexBuffer.h Renderer.cpp Renderer.h Shader.cpp Shader.h)

target_link_libraries(ray_tracing glfw)
target_link_libraries(ray_tracing GLEW::GLEW)
target_link_libraries(ray_tracing glm::glm)

# Copy resources to build directory
add_custom_target(
        copy_resources
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
        COMMENT "Copying resources to build directory"
)

add_dependencies(ray_tracing copy_resources)