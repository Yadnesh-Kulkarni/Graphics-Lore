#pragma once
#include "Core.h"

class Texture2D
{
public:
	Texture2D(std::string& path, GLenum type);
	GLuint GetTexture() { return m_texture; }
	void UseTexture();
protected:
	GLuint m_texture;
	GLenum m_type;
};

