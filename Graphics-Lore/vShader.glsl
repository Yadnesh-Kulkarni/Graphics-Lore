#version 450 core
in vec4 vPosition;
in vec4 vColor;
in vec2 vTex;

out vec4 color;
out vec2 TexCoord;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

void main()
{
	gl_Position = projection * view * model  * vPosition;
	color = vColor;
	TexCoord = vTex;
}