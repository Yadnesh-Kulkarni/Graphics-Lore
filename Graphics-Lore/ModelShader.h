#pragma once
#include "Core.h"

class ModelShader
{
public:
	ModelShader(std::string vertexShader, std::string fragmentShader, std::string tessShader, std::string geometryShader);

	~ModelShader();

	void Use();

	void setUniformBool (const std::string& name, bool val);
	void setUniformInt  (const std::string& name, int val);
	void setUniformFloat(const std::string& name, float val);
	void setUniformVec4 (const std::string& name, float x, float y, float z, float w);
	void setUniformMat4(const std::string& name, glm::mat4 val);
private:
	GLuint m_shaderProgram;
	std::vector<GLuint> m_shaders;

	bool		LinkShaders();
	GLuint		CompileShader(GLenum type, const char* source);


	void readShaderFromFile(const std::string& path, GLenum shaderType);
};

