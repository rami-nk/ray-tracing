#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "VertexArray.h"

class Renderer {

public:
    static void ClearColor(glm::vec4 color);
    static void Clear();

    static void Draw(VertexArray& va, int count);
};