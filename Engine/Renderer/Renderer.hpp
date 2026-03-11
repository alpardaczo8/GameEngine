#pragma once 

#include <memory>

#include <GLAD/glad.h>
#include <Renderer/Shader.hpp>

class Renderer {
public:
    void init();
    void clear();
    void draw();

private:
    unsigned int m_VAO, m_VBO;
    unsigned int m_shaderProgram;

    std::unique_ptr<Shader> m_shader;
};