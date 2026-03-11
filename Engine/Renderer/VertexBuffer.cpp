#include "Renderer/VertexBuffer.hpp"

VertexBuffer::VertexBuffer(const void *data, unsigned int size)
{
    glGenBuffers(1, &m_ID);
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    if (m_ID)
    {
        glDeleteBuffers(1, &m_ID);
    }
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept
    : m_ID(other.m_ID)
{
    other.m_ID = 0; // Prevent deletion of the resource
}

VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept
{
    if (this != &other)
    {
        // Clean up existing resource
        if (m_ID)
        {
            glDeleteBuffers(1, &m_ID);
        }

        // Transfer ownership
        m_ID = other.m_ID;
        other.m_ID = 0; // Prevent deletion of the resource
    }
    return *this;
}
