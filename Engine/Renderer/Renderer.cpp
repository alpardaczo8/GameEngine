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

    m_VAO = std::make_unique<VertexArray>();
    m_VBO = std::make_unique<VertexBuffer>(vertices, sizeof(vertices));

    m_VAO->bind();
    m_VBO->bind();

    m_VAO->setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    m_VAO->enableVertexAttribArray(0);
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
    
    m_VAO->bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);  

}
