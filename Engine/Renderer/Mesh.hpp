#pragma once

#include <memory>
#include <vector>

#include <Renderer/VertexArray.hpp>
#include <Renderer/VertexBuffer.hpp>
#include <Renderer/IndexBuffer.hpp>
#include <Renderer/VertexBufferLayout.hpp>

class Mesh {
public:
    Mesh(const void *vertices, const unsigned int* indices, int indexCount, const VertexBufferLayout& layout);
    Mesh(std::vector<float> verticies,
            std::vector<unsigned int> indicies,
            const VertexBufferLayout& layout);
    ~Mesh();

    void bind() const;
    void unbind() const;

    int getIndexCount() const { return m_indexCount; }

    Mesh (const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

private:
    VertexArray m_VAO;
    VertexBuffer m_VBO;
    IndexBuffer m_IBO;
    int m_indexCount;
};
