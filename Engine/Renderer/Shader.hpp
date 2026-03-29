#pragma once

#include <string>
#include <glm/glm.hpp>

class Shader {
public:
    Shader();
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void use() const;
    void setMat4(const std::string& name, const glm::mat4& value) const;
    void setInt(const std::string& name, int value) const;

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;

private:
    unsigned int m_ID;
    std::string loadShaderSource(const char* filePath);
};