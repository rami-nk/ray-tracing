#include "VertexArray.h"

void VertexArray::addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) const {
    bind();
    vb.bind();
    const auto& elements = layout.getElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset);
        glEnableVertexAttribArray(i);
        offset += element.count * LayoutElement::getSizeOfType(element.type);
    }
}

VertexArray::VertexArray() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VAO);
    bind();
}

VertexArray::~VertexArray() {
    glBindVertexArray(0);
}

void VertexArray::bind() const {
    glBindVertexArray(VAO);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}