#pragma once

#include <GLAD/glad.h>
#include <Renderer/VertexBuffer.hpp>
#include <Renderer/VertexBufferLayout.hpp>

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void bind() const;
    void unbind() const;
    void addVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void setVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) const;
    void enableVertexAttribArray(GLuint index) const;

    VertexArray(const VertexArray&) = delete;
    VertexArray& operator=(const VertexArray&) = delete;

    VertexArray(VertexArray&& other) noexcept;
    VertexArray& operator=(VertexArray&& other) noexcept;
private:
    GLuint m_ID;
};