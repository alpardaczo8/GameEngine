#include <Renderer/Renderer.hpp>
#include <iostream>

void Renderer::init()
{
    // Initialize OpenGL state here
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0,0,800,600);
    m_shader = std::make_unique<Shader>(
        "assets/triangle.vert",
        "assets/triangle.frag"
    );

    float vertices[] =
    {
        -0.5f,-0.5f,0.0f,
         0.5f,-0.5f,0.0f,
         0.0f, 0.5f,0.0f
    };

    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    glBufferData(
        GL_ARRAY_BUFFER, 
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW
    );

    glVertexAttribPointer(
        0,              // shader location
        3,              // 3 komponens
        GL_FLOAT,
        GL_FALSE,
        3 * sizeof(float),
        (void*)0
    );

    glEnableVertexAttribArray(0);
    GLint enabled;
    glGetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);
}

void Renderer::clear()
{
    // Clear the screen
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw()
{
    // Issue draw calls here
    m_shader->use();
    
    glBindVertexArray(m_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);  

}
