#include <Renderer/Material.hpp>

Material::Material(const std::string& name, const std::shared_ptr<Shader>& shader, const std::shared_ptr<Texture>& texture)
    : m_Name(name), m_Shader(shader), m_Texture(texture)
{
}

void Material::use() const
{
    if (m_Shader)
    {
        m_Shader->use();
        
        if (m_Texture)
        {
            m_Texture->bind(0);
            m_Shader->setInt("u_Texture",0);
        }
    }
}

