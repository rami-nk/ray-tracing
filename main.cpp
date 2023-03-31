#include <iostream>

#include <GLFW/glfw3.h>

int main() {

    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 600, "Ray tracing", nullptr, nullptr);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
