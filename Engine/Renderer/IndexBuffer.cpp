#include "Renderer/IndexBuffer.hpp"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : m_count(count)
{
    glGenBuffers(1, &m_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    if (m_ID)
    {
        glDeleteBuffers(1, &m_ID);
    }
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void IndexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::IndexBuffer(IndexBuffer&& other) noexcept
    : m_ID(other.m_ID), m_count(other.m_count)
{
    other.m_ID = 0; // Prevent deletion of the resource
    other.m_count = 0;
}

IndexBuffer& IndexBuffer::operator=(IndexBuffer&& other) noexcept
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
        m_count = other.m_count;

        other.m_ID = 0; // Prevent deletion of the resource
        other.m_count = 0;
    }
    return *this;
}
