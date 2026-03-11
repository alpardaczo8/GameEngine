#pragma once

#include <string>

class Shader {
public:
    Shader();
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void use() const;

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;

private:
    unsigned int m_ID;
    std::string loadShaderSource(const char* filePath);
};