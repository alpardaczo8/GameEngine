#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aUV;

out vec2 v_UV;
out vec3 v_Pos;

uniform mat4 u_ViewProjection;
uniform mat4 u_Model;

void main()
{
    v_UV = aUV;
    v_Pos = aPos;
    gl_Position = u_ViewProjection * u_Model * vec4(aPos, 1.0);
}