#include <Renderer/RenderCommand.hpp>

void RenderCommand::init()
{
    // Initialize OpenGL state here
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0,0,800,600);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}

void RenderCommand::drawIndexed(const VertexArray& VAO, unsigned int indexCount)
{
    VAO.bind();
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
}

void RenderCommand::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderCommand::setClearColor(const glm::vec4& color)
{
    glClearColor(color.r, color.g, color.b, color.a);
}