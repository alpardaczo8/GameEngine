#pragma once

#include <Renderer/Shader.hpp>
#include <memory>
#include <string>

class Material
{
public:
    Material(const std::string& name, const std::shared_ptr<Shader>& shader);
    ~Material() = default;

    const std::string& getName() const { return m_Name; }
    const std::shared_ptr<Shader>& getShader() const { return m_Shader; }

    Material(const Material&) = delete;
    Material& operator=(const Material&) = delete;

    void use() const;
private:
    std::string m_Name;
    std::shared_ptr<Shader> m_Shader;
};