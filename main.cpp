#include "GL/glew.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Shader.h"

#include <GLFW/glfw3.h>

#include <iostream>

int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    glfwSetErrorCallback([](int error, const char* description) {
        // Error callback
        fprintf(stderr, "GLFW Error %d: %s\n", error, description);
    });

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Ray Tracing", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        // make sure the viewport matches the new window dimensions; note that width and
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    });

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) std::cout << "Glew init failed!" << std::endl;

    // enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    std::cout << glGetString(GL_VERSION) << std::endl;

    auto shader = std::make_unique<Shader>("resources/shaders/default.glsl");

    float vertices[] = {
            -0.5f, -0.5f, 0.0f, // left
            0.5f, -0.5f, 0.0f, // right
            0.0f,  0.5f, 0.0f  // top
    };

    VertexArray vertexArray;
    VertexBuffer vertexBuffer(vertices, sizeof(vertices));

    VertexBufferLayout layout;
    layout.PushFloat(3);

    vertexArray.AddBuffer(vertexBuffer, layout);

    vertexBuffer.Unbind();

    vertexArray.Unbind();

    while (!glfwWindowShouldClose(window)) {
        Renderer::ClearColor({0.2f, 0.3f, 0.3f, 1.0f});
        Renderer::Clear();

        shader->Bind();
        vertexArray.Bind();
        Renderer::Draw(vertexArray, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}