#pragma once

#include <GL/glew.h>
#include <stdexcept>

class LayoutElement {
public:
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT:
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
            default: throw std::runtime_error("Unknown type");
        }
    }
};