#include "ModelShader.h"

ModelShader::~ModelShader()
{
	if (m_shaderProgram)
	{
		glDeleteProgram(m_shaderProgram);
	}
}

bool ModelShader::SetupShaders(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
	if (vertexShader == 0)
	{
		return false;
	}

	GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
	if (fragmentShader == 0)
	{
		return false;
	}

	std::vector<GLuint> shaders;
	shaders.push_back(vertexShader);
	shaders.push_back(fragmentShader);

	if (!LinkShaders(shaders))
	{
		return false;
	}

	for (GLuint& shader : shaders)
	{
		glDeleteShader(shader);
	}

	return true;
}

GLuint ModelShader::CompileShader(GLenum type, const char* source)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR : SHADER : COMPILATION_FAILED\n" << infoLog << std::endl;
		return 0;
	}
	return shader;
}

bool ModelShader::LinkShaders(std::vector<GLuint> shaders)
{
	m_shaderProgram = glCreateProgram();
	for (GLuint& shader : shaders)
	{
		glAttachShader(m_shaderProgram, shader);
	}
	
	glBindAttribLocation(m_shaderProgram, Attribute::VERTEX_ATTRIB, "vPosition");

	int success;
	char infoLog[512];
	glLinkProgram(m_shaderProgram);
	glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR : PROGRAM : LINK_FAILED\n" << infoLog << std::endl;
		return false;
	}

	return true;
}

