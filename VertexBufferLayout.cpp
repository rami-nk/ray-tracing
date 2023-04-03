#include "VertexBufferLayout.h"

void VertexBufferLayout::PushFloat(unsigned int count) {
    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_Stride += count * LayoutElement::getSizeOfType(GL_FLOAT);
}