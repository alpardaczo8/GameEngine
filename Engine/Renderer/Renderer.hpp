#pragma once 

#include <memory>

#include <GLAD/glad.h>
#include <Renderer/Shader.hpp>
#include <Renderer/VertexArray.hpp>
#include <Renderer/VertexBuffer.hpp>

class Renderer {
public:
    void init();
    void clear();
    void draw();

private:
    std::unique_ptr<VertexArray> m_VAO;
    std::unique_ptr<VertexBuffer> m_VBO;
    std::unique_ptr<Shader> m_shader;
};