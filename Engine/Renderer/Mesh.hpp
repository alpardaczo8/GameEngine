#pragma once

#include <memory>

#include <Renderer/VertexArray.hpp>
#include <Renderer/VertexBuffer.hpp>
#include <Renderer/IndexBuffer.hpp>
#include <Renderer/VertexBufferLayout.hpp>

class Mesh {
public:
    Mesh(const void *vertices, unsigned int vertexSize, const unsigned int* indices, unsigned int indexCount, const VertexBufferLayout& layout);
    ~Mesh();

    void bind() const;
    void unbind() const;

    int getIndexCount() const { return m_indexCount; }

private:
    std::unique_ptr<VertexArray> m_VAO;
    std::unique_ptr<VertexBuffer> m_VBO;
    std::unique_ptr<IndexBuffer> m_IBO;
    int m_indexCount;
};
