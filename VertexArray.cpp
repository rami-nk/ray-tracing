#include "VertexArray.h"

void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) const {
    Bind();
    vb.Bind();
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
    Bind();
}

VertexArray::~VertexArray() {
    glBindVertexArray(0);
}

void VertexArray::Bind() const {
    glBindVertexArray(VAO);
}

void VertexArray::Unbind() const {
    glBindVertexArray(0);
}