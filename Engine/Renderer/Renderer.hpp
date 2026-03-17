#pragma once 

#include <memory>
#include <vector>

#include <Renderer/Material.hpp>
#include <Renderer/Mesh.hpp>

struct RenderItem
{
    const Mesh *mesh;
    const Material *material;
};

class Renderer {
public:
    void init();
    void clear();

    void beginScene();
    void endScene();
    void submit(const Mesh& mesh, const Material& material);
    void flush();

private:
    std::vector<RenderItem> m_renderQueue;


};