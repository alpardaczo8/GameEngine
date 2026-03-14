#pragma once

#include <GLAD/glad.h>

class IndexBuffer {
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

    unsigned int getCount() const { return m_count; }

    IndexBuffer(const IndexBuffer&) = delete;
    IndexBuffer& operator=(const IndexBuffer&) = delete;

    IndexBuffer(IndexBuffer&& other) noexcept;
    IndexBuffer& operator=(IndexBuffer&& other) noexcept;
private:
    unsigned int m_ID;
    unsigned int m_count;
};
