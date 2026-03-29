#include <Renderer/Material.hpp>

Material::Material(const std::string& name, const std::shared_ptr<Shader>& shader)
    : m_Name(name), m_Shader(shader)
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

