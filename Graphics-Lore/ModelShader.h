#pragma once
#include "Core.h"

class ModelShader
{
public:
	~ModelShader();
	bool SetupShaders(const char* vertexShader, const char* fragmentShader);
	GLuint GetShaderProgram() { return m_shaderProgram; };
private:
	GLuint m_shaderProgram;
	GLuint CompileShader(GLenum type, const char* source);
	bool LinkShaders(std::vector<GLuint> shaders);
};

