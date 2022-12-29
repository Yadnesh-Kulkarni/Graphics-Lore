#pragma once
#include "Core.h"
#include "ModelShader.h"

class Drawable
{
public:
	virtual void InitData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices) = 0;
	virtual void Draw() = 0;

protected:

	GLuint m_Vao;
	GLuint m_Vbo;
	GLuint m_Ebo;

	ModelShader* shader;
};

