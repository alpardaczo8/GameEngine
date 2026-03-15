#include <Renderer/Renderer.hpp>
#include <iostream>

void Renderer::init()
{
    // Initialize OpenGL state here
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0,0,800,600);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}

void Renderer::clear()
{
    // Clear the screen
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const Mesh& mesh, const Shader& shader)
{
    shader.use();
    mesh.bind();
    glDrawElements(GL_TRIANGLES, mesh.getIndexCount(), GL_UNSIGNED_INT, nullptr);
}
