#pragma once
#include "Drawable.h"

Drawable::Drawable()
{
	glGenVertexArrays(1, &m_Vao);
	glBindVertexArray(m_Vao);
}

Drawable::~Drawable()
{
	if (m_Vao)
	{
		glDeleteVertexArrays(1, &m_Vao);
	}

	for(auto& vbo : m_Vbo)
	{
		glDeleteBuffers(1, &vbo);
	}

	if (m_Ebo)
	{
		glDeleteBuffers(1, &m_Ebo);
	}
}

void Drawable::InitData()
{

	InitVertices();
	
	InitColor();

	InitTexture();

	InitIndices();
}

void Drawable::Draw()
{
	glBindVertexArray(m_Vao);
}

void Drawable::InitVertices()
{
	if (m_vertices.size() == 0)
	{
		return;
	}

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(m_vertices), &m_vertices[0], GL_STATIC_DRAW);
	
	glVertexAttribPointer(Attribute::VERTEX_ATTRIB, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(Attribute::VERTEX_ATTRIB);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	m_Vbo.push_back(vbo);
}

void Drawable::InitColor()
{
	if (m_color.size() == 0)
	{
		return;
	}

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_color.size() * sizeof(m_color), &m_color[0], GL_STATIC_DRAW);

	glVertexAttribPointer(Attribute::VERTEX_COLOR, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(Attribute::VERTEX_COLOR);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	m_Vbo.push_back(vbo);
}

void Drawable::InitTexture()
{
	if (m_tex.size() == 0)
	{
		return;
	}

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_tex.size() * sizeof(m_tex), &m_tex[0], GL_STATIC_DRAW);

	glVertexAttribPointer(Attribute::VERTEX_TEXTURE, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(Attribute::VERTEX_TEXTURE);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	m_Vbo.push_back(vbo);
}

void Drawable::InitIndices()
{
	if (m_indices.size() == 0)
	{
		return;
	}
	glGenBuffers(1, &m_Ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(m_indices), &m_indices[0], GL_STATIC_DRAW);
}
