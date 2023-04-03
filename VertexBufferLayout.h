#pragma once

#include <vector>
#include "LayoutElement.h"

class VertexBufferLayout {
public:
    VertexBufferLayout() = default;

    void pushFloat(unsigned int count);

    [[nodiscard]] inline const std::vector<LayoutElement>& getElements() const { return m_Elements; }
    [[nodiscard]] inline unsigned int getStride() const { return m_Stride; }
private:
    std::vector<LayoutElement> m_Elements;
    unsigned int m_Stride{};
};