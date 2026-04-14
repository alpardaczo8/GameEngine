#include "Renderer/Mesh.hpp"
#include "Core/Logger.hpp"

Mesh::Mesh(std::vector<float> verticies, std::vector<unsigned int> indicies, const VertexBufferLayout& layout)
    : m_VAO(), m_VBO(verticies.data(), verticies.size() * sizeof(float)), m_IBO(indicies.data(), indicies.size()),
        m_indexCount(static_cast<unsigned int>(indicies.size()))
{
    m_VAO.bind();
    m_VBO.bind();
    m_IBO.bind();

    m_VAO.addVertexBuffer(m_VBO, layout);
}

Mesh::~Mesh()
{
    // Resources will be automatically released by their destructors
}

void Mesh::bind() const
{
    m_VAO.bind();
    m_IBO.bind();
}

void Mesh::unbind() const
{
    m_VAO.unbind();
    m_IBO.unbind();
}
