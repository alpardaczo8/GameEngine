#version 460 core

in vec2 v_UV;
in vec3 v_Normal;
in vec3 v_FragPos;

out vec4 FragColor;
uniform vec3 u_LightPos;
uniform vec3 u_LightColor;
uniform vec3 u_ViewPos;

uniform sampler2D u_Texture;

void main()
{
    vec3 texColor = texture(u_Texture, v_UV).rgb;

    // Ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * u_LightColor;

    // Diffuse
    vec3 norm = normalize(v_Normal);
    vec3 lightDir = normalize(u_LightPos - v_FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * u_LightColor;

    // Specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(u_ViewPos - v_FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    vec3 specular = specularStrength * spec * u_LightColor;

    vec3 result = (ambient + diffuse + specular) * texColor;
    FragColor = vec4(result, 1.0);
}