#pragma once

#include "VertexBufferLayout.h"
#include "VertexBuffer.h"

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const;

    void bind() const;
    void unbind() const;

private:
    unsigned int VAO{};
};