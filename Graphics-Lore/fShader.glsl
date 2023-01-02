#version 450 core

in vec4 color;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D tex1;
uniform sampler2D tex2;

void main()
{
	FragColor = mix(texture(tex1, TexCoord), texture(tex2, TexCoord) , 0.5f);
}