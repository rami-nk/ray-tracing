#include "Renderer.h"

void Renderer::ClearColor(glm::vec4 color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

void Renderer::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(VertexArray &va, int count) {
    glDrawArrays(GL_TRIANGLES, 0, count);
}