#include <Renderer/VertexBufferLayout.hpp>


VertexBufferLayout::VertexBufferLayout(const void *data, unsigned int size)
    : m_stride(0)
{
    // Constructor implementation (if needed)
}

VertexBufferLayout::~VertexBufferLayout()
{
    // Destructor implementation (if needed)
}

template<>
void VertexBufferLayout::push<float>(unsigned int count)
{
    m_elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
}
