#include "Renderer/Mesh.hpp"

Mesh::Mesh(const void * vertices, unsigned int vertexSize, const unsigned int* indices, unsigned int indexCount, const VertexBufferLayout& layout)
    : m_indexCount(indexCount)
{
    m_VAO = std::make_unique<VertexArray>();
    m_VBO = std::make_unique<VertexBuffer>(vertices, vertexSize);
    m_IBO = std::make_unique<IndexBuffer>(indices, indexCount);

    m_VAO->addVertexBuffer(*m_VBO, VertexBufferLayout(vertices, vertexSize));

    m_VAO->addVertexBuffer(*m_VBO, layout);
}

Mesh::~Mesh()
{
    // Resources will be automatically released by unique_ptr destructors   
}

void Mesh::bind() const
{
    m_VAO->bind();
    m_IBO->bind();
}

void Mesh::unbind() const
{
    m_VAO->unbind();
    m_IBO->unbind();
}
