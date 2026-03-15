#pragma once

#include <GLAD/glad.h>
#include <vector>
#include <stdexcept>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT: return sizeof(float);
            case GL_UNSIGNED_INT: return sizeof(unsigned int);
            case GL_UNSIGNED_BYTE: return sizeof(unsigned char);
            default:
                throw std::runtime_error("Unknown type in VertexBufferElement!");
        }
    }
};

class VertexBufferLayout {
public:
    VertexBufferLayout(const void *data, unsigned int size);
    ~VertexBufferLayout();

    template<typename T>
    void push(unsigned int count);

    const std::vector<VertexBufferElement>& getLayout() const { return m_elements; }
    unsigned int getStride() const { return m_stride; };

    // VertexBufferLayout(const VertexBufferLayout&) = delete;
    // VertexBufferLayout& operator=(const VertexBufferLayout&) = delete;

    // VertexBufferLayout(VertexBufferLayout&& other) noexcept;
    // VertexBufferLayout& operator=(VertexBufferLayout&& other) noexcept;
private:
    std::vector<VertexBufferElement> m_elements;
    unsigned int m_stride;
};
