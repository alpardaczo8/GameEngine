#include "Renderer/VertexArray.hpp"
#include <stdexcept>
#include <string>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_ID);
}

VertexArray::~VertexArray()
{
    if (m_ID)
    {
        glDeleteVertexArrays(1, &m_ID);
    }
}

void VertexArray::bind() const
{
    glBindVertexArray(m_ID);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::addVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    bind();
    vb.bind();
    const auto& elements = layout.getLayout();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        setVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset);
        enableVertexAttribArray(i);
        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::setVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) const
{
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void VertexArray::enableVertexAttribArray(GLuint index) const
{
    glEnableVertexAttribArray(index);
    GLint enabled;
    glGetVertexAttribiv(index, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);
    if (!enabled)
    {
        throw std::runtime_error("Vertex attribute array " + std::to_string(index) + " is not enabled!");
    }
}

VertexArray::VertexArray(VertexArray&& other) noexcept
    : m_ID(other.m_ID)
{
    other.m_ID = 0; // Prevent deletion of the resource
}

VertexArray& VertexArray::operator=(VertexArray&& other) noexcept
{
    if (this != &other)
    {
        // Clean up existing resource
        if (m_ID)
        {
            glDeleteVertexArrays(1, &m_ID);
        }

        // Transfer ownership
        m_ID = other.m_ID;
        other.m_ID = 0; // Prevent deletion of the resource
    }
    return *this;
}