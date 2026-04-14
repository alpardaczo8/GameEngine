#pragma once

#include <GLAD/glad.h>
#include <Renderer/VertexArray.hpp>
#include <glm/vec4.hpp>

class RenderCommand {
public:
    static void init(int width, int height);
    static void drawIndexed(const VertexArray& VAO, unsigned int indexCount);
    static void clear();
    static void setClearColor(const glm::vec4& color);
};
