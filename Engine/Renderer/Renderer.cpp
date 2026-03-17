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

void Renderer::beginScene()
{
    m_renderQueue.clear();
}

void Renderer::endScene()
{
    flush();
}

void Renderer::submit(const Mesh& mesh, const Material& material)
{
    
    m_renderQueue.push_back({&mesh, &material});
}

void Renderer::flush()
{

    for (const auto& item : m_renderQueue)
    {
        item.material->use();
        RenderCommand::drawIndexed(*item.mesh->getVAO(), item.mesh->getIndexCount());
    }
}