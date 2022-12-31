#include "ModelShader.h"

ModelShader::ModelShader(std::string vertexShader, std::string fragmentShader, std::string tessShader, std::string geometryShader)
{
	if (vertexShader.length() == 0)
	{
		vertexShader = "defaultVertexShader.glsl";
	}
	if (fragmentShader.length() == 0)
	{
		fragmentShader = "defaultFragmentShader.glsl";
	}

	m_shaderProgram = 0;
	readShaderFromFile(vertexShader, GL_VERTEX_SHADER);
	readShaderFromFile(fragmentShader, GL_FRAGMENT_SHADER);
	readShaderFromFile(tessShader, GL_TESS_CONTROL_SHADER);
	readShaderFromFile(geometryShader, GL_GEOMETRY_SHADER);

	if (!LinkShaders())
	{
		std::cout << __FUNCTION__ << " : SHADER_LINKING_FAILED" << std::endl;
	}
}

ModelShader::~ModelShader()
{
	for (GLuint& shader : m_shaders)
	{
		glDeleteShader(shader);
	}

	if (m_shaderProgram)
	{
		glDeleteProgram(m_shaderProgram);
	}
}

void ModelShader::Use()
{
	glUseProgram(m_shaderProgram);
}

void ModelShader::setUniformBool(const std::string& name, bool val)
{
	int loc = glGetUniformLocation(m_shaderProgram, name.c_str());
	if (loc == -1)
	{
		std::cout << __FUNCTION__ << " : " << name << " does not exist" << std::endl;
		return;
	}
	glUniform1i(loc, val);
}

void ModelShader::setUniformInt(const std::string& name, int val)
{
	int loc = glGetUniformLocation(m_shaderProgram, name.c_str());
	if (loc == -1)
	{
		std::cout << __FUNCTION__ << " : " << name << " does not exist" << std::endl;
		return;
	}
	glUniform1i(loc, val);
}

void ModelShader::setUniformFloat(const std::string& name, float val)
{
	int loc = glGetUniformLocation(m_shaderProgram, name.c_str());
	if (loc == -1)
	{
		std::cout << __FUNCTION__ << " : " << name << " does not exist" << std::endl;
		return;
	}
	glUniform1f(loc, val);
}

void ModelShader::setUniformVec4(const std::string& name, float x, float y, float z, float w)
{
	int loc = glGetUniformLocation(m_shaderProgram, name.c_str());
	if (loc == -1)
	{
		std::cout << __FUNCTION__ << " : " << name << " does not exist" << std::endl;
		return;
	}

	glUniform4f(loc, x, y, z, w);
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

bool ModelShader::LinkShaders()
{
	m_shaderProgram = glCreateProgram();
	for (GLuint& shader : m_shaders)
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
		std::cout << __FUNCTION__ << " : PROGRAM: LINK_FAILED\n" << infoLog << std::endl;
		return false;
	}

	return true;
}

void ModelShader::readShaderFromFile(const std::string& path, GLenum shaderType)
{
	if (path.length() == 0)
		return;

	std::string shaderCode;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		shaderFile.open(path);

		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();

		shaderFile.close();
		shaderCode = shaderStream.str();
	}
	catch(std::ifstream::failure e)
	{
		std::cout << __FUNCTION__ << "FILE_READ_UNSUCCESSFULL" << std::endl;
	}

	GLuint shader = CompileShader(shaderType, shaderCode.c_str());
	if (shader == 0)
	{
		std::cout << __FUNCTION__ << " : VERTEX_COMPILATION_FAILED" << std::endl;
	}

	m_shaders.push_back(shader);
}

