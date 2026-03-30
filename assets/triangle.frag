#version 460 core

in vec2 v_UV;
in vec3 v_Pos;
out vec4 FragColor;

uniform sampler2D u_Texture;

void main()
{
    FragColor = texture(u_Texture, v_UV);
//    FragColor = vec4(1.0, 1.0, 0.0, 0.0);
   //FragColor = vec4(v_Pos, 0.0);
}