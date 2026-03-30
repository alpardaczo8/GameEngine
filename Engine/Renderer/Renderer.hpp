#pragma once 

#include <memory>
#include <vector>

#include <Renderer/Material.hpp>
#include <Renderer/Mesh.hpp>
#include <Renderer/Camera.hpp>

#include <glm/glm.hpp>

struct RenderItem
{
    const Mesh *mesh;
    const Material *material;
    glm::mat4 modelMatrix{1.0f};
};

struct SceneData
{
    glm::mat4 viewProjectionMatrix;
};

class Renderer {
public:
    void init();
    void clear();

    void beginScene(const Camera& camera);
    void endScene();
    void submit(const Mesh& mesh, const Material& material, const glm::mat4& transform = glm::mat4(1.0f));
    void flush();

private:
    std::vector<RenderItem> m_renderQueue;
    SceneData m_sceneData;

};