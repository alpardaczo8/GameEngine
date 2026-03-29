#pragma once

#include <GLAD/glad.h>

#include <string>

class Texture {
public:
    Texture() = default;
    Texture(const std::string& path);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    int getChannels() const { return m_channels; }
    const std::string& getPath() const { return m_path; }

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    Texture(Texture&&) noexcept;
    Texture& operator=(Texture&&) noexcept;

private:
    GLuint m_ID;
    int m_width;
    int m_height;
    int m_channels;
    std::string m_path;
};