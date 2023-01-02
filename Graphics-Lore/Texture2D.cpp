#include "Texture2D.h"
#include "stb_image.h"
#include "Core.h"

Texture2D::Texture2D(std::string& path, GLenum type)
{
	m_texture = 0;
	m_type = type;
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
	if (data == nullptr)
	{
		std::cout << __FUNCTION__ << " : Unable to read texture file" << std::endl;
	}

	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	if (data)
	{
		stbi_image_free(data);
	}

	UseTexture();
}

void Texture2D::UseTexture()
{
	glActiveTexture(m_type);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}
