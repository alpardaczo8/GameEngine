#pragma once 

#include <memory>

#include <GLAD/glad.h>
#include <Renderer/Shader.hpp>
#include <Renderer/Mesh.hpp>

class Renderer {
public:
    void init();
    void clear();
    void draw(const Mesh& mesh, const Shader& shader);
};