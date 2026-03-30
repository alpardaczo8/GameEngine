#include <Renderer/Renderer.hpp>
#include <Renderer/RenderCommand.hpp>

#include <iostream>

void Renderer::init()
{
    RenderCommand::init();
}

void Renderer::clear()
{
    // Clear the screen
    RenderCommand::setClearColor({0.1f, 0.1f, 0.1f, 1.0f});
    RenderCommand::clear();
}

void Renderer::beginScene(const Camera& camera)
{
    m_sceneData.viewProjectionMatrix = camera.getProjectionMatrix() * camera.getViewMatrix();
    m_renderQueue.clear();
}

void Renderer::endScene()
{
    flush();
}

void Renderer::submit(const Mesh& mesh, const Material& material, const glm::mat4& transform)
{
    m_renderQueue.push_back({&mesh, &material, transform});
}

void Renderer::flush()
{

    for (const auto& item : m_renderQueue)
    {
        item.material->use();
        item.material->getShader()->setMat4("u_ViewProjection", m_sceneData.viewProjectionMatrix);
        item.material->getShader()->setMat4("u_Model", item.modelMatrix);
        RenderCommand::drawIndexed(*item.mesh->getVAO(), item.mesh->getIndexCount());
    }
}