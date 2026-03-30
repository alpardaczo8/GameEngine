#pragma once

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

class Shader {
public:
    Shader() = default;
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    int getUniformLocation(const std::string& name) const;

    void use() const;
    void reload();
    void setMat4(const std::string& name, const glm::mat4& value) const;
    void setVec3(const std::string& name, const glm::vec3& vec) const;
    void setInt(const std::string& name, int value) const;

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;

private:
    unsigned int m_ID = 0;
    std::string m_vertexShaderPath;
    std::string m_fragmentShaderPath;
    mutable std::unordered_map<std::string, int> m_uniformCache;
    std::string loadShaderSource(const char* filePath);

    void compile();
};