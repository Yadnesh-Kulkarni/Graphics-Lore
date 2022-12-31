#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
	if (m_Vao)
	{
		glDeleteVertexArrays(1, &m_Vao);
	}

	if (m_Vbo)
	{
		glDeleteBuffers(1, &m_Vbo);
	}

	if (m_Ebo)
	{
		glDeleteBuffers(1, &m_Ebo);
	}

	if (shader)
	{
		delete shader;
	}
}

void Model::InitData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices)
{
	shader = new ModelShader(this->m_vertexShader, this->m_fragmentShader, this->m_tessShader, this->m_geomShader);
	// This part needs to be further abstracted
	glGenVertexArrays(1, &m_Vao);
	glBindVertexArray(m_Vao);

	glGenBuffers(1, &m_Vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &m_Ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(Attribute::VERTEX_ATTRIB, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);
	glEnableVertexAttribArray(Attribute::VERTEX_ATTRIB);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Model::Draw()
{
	shader->Use();
	glBindVertexArray(m_Vao);
}
