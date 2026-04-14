#include <Renderer/Texture.hpp>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include <stb_image.h>

#include <stdexcept>

Texture::Texture(const std::string& path)
{
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path.c_str(), &m_width, &m_height, &m_channels, 0);
    if (!data)
    {
        throw std::runtime_error("Failed to load texture: " + path);
    }
    glGenTextures(1, &m_ID);
    glBindTexture(GL_TEXTURE_2D, m_ID);

    GLenum format = GL_RGBA;
    if (m_channels == 1) format = GL_RED;
    else if (m_channels == 3) format = GL_RGB;
    else if (m_channels == 4) format = GL_RGBA;
    GLenum internalFormat = format;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, m_width, m_height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

void Texture::bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
    if (m_ID)
        glDeleteTextures(1, &m_ID);
}

Texture::Texture(Texture&& other) noexcept
    : m_ID(other.m_ID), m_height(other.m_height), m_width(other.m_width), m_channels(other.m_channels), m_path(other.m_path)
{
    other.m_ID = 0; // Prevent deletion of the resource
}

Texture& Texture::operator=(Texture&& other) noexcept 
{
	if (this != &other)
    {
        if (m_ID)
        {
            glDeleteTextures(1, &m_ID);
        }
        m_ID = other.m_ID;
        m_height = other.m_height;
        m_width = other.m_width;
        m_channels = other.m_channels;
        m_path = other.m_path;

        other.m_ID = 0; // Prevent deletion of the resource
    }
    return *this;
}
