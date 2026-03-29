#include "Renderer/Shader.hpp"

#include <Core/Logger.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

#include <GLAD/glad.h>

#include <glm/gtc/type_ptr.hpp>

Shader::Shader()
{
    // Constructor implementation (if needed)
}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    // Load and compile shaders here
    std::string vertexCode = loadShaderSource(vertexPath);
    std::string fragmentCode = loadShaderSource(fragmentPath);

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    // Vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        throw std::runtime_error("Vertex shader compilation failed: " + std::string(infoLog));
    }

    // Fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        throw std::runtime_error("Fragment shader compilation failed: " + std::string(infoLog));
    }

    // Shader Program
    m_ID = glCreateProgram();
    glAttachShader(m_ID, vertex);
    glAttachShader(m_ID, fragment);
    glBindFragDataLocation(m_ID, 0, "FragColor");
    glLinkProgram(m_ID);
    glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_ID, 512, nullptr, infoLog);
        throw std::runtime_error("Shader program linking failed: " + std::string(infoLog));
         char log[512];
        glGetShaderInfoLog(m_ID, 512, NULL, log);
    }


    glValidateProgram(m_ID);
	glGetProgramiv(m_ID, GL_VALIDATE_STATUS, &success);
	if (!success) 
	{
		glGetProgramInfoLog(m_ID, sizeof(infoLog), NULL, infoLog);
		printf("Error validating program: '%s'\n", infoLog);
		return;
	}
    // Clean up shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{
    if (m_ID)
    {
        glDeleteProgram(m_ID);
    }
}

void Shader::use() const
{
    glUseProgram(m_ID);
}

void Shader::setMat4(const std::string& name, const glm::mat4& matrix) const
{
    int location = glGetUniformLocation(m_ID, name.c_str());
    if (location == -1)
    {
        ENG_ERROR("Uniform " + name + " not found in shader program");
        return;
    }
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::setInt(const std::string&name, int value) const
{
    int location = glGetUniformLocation(m_ID, name.c_str());
    if (location == -1)
    {
        ENG_ERROR("Uniform " + name + " not found in shader program");
        return;
    }
    glUniform1i(location, value);
}

std::string Shader::loadShaderSource(const char* filePath)
{
    std::ifstream shaderFile;
    std::stringstream shaderStream;

    shaderFile.open(filePath);
    if (!shaderFile.is_open())
    {
        throw std::runtime_error("Failed to open shader file: " + std::string(filePath));
    }
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();

    return shaderStream.str();
}

Shader::Shader(Shader&& other) noexcept
    : m_ID(other.m_ID)
{
    other.m_ID = 0; // Prevent deletion of the resource
}

Shader& Shader::operator=(Shader&& other) noexcept
{
    if (this != &other)
    {
        // Clean up existing resource
        if (m_ID)
        {
            glDeleteProgram(m_ID);
        }

        // Transfer ownership
        m_ID = other.m_ID;
        other.m_ID = 0; // Prevent deletion of the resource
    }
    return *this;
}