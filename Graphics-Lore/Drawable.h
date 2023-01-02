#pragma once
#include "Core.h"
#include "ModelShader.h"

class Drawable
{
public:
	Drawable();
	~Drawable();
	virtual void InitData();
	virtual void Draw();

	void SetVertices(std::vector<GLfloat>& vertices) { m_vertices = vertices; }
	void SetColors(std::vector<GLfloat>& colors) { m_color = colors; }
	void SetTexels(std::vector<GLfloat>& tex) { m_tex = tex; }
	void SetIndices(std::vector<GLuint>& indices) { m_indices = indices; }

protected:

	GLuint m_Vao;
	std::vector<GLuint> m_Vbo;
	GLuint m_Ebo;

	ModelShader* shader;

	std::vector<GLfloat> m_vertices;
	std::vector<GLfloat> m_color;
	std::vector<GLfloat> m_tex;
	std::vector<GLuint> m_indices;

private:
	void InitVertices();
	void InitColor();
	void InitTexture();
	void InitIndices();
};

