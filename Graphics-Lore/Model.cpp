#include "Model.h"

Model::Model()
{
}

Model::~Model()
{

	if (shader)
	{
		delete shader;
	}
}

void Model::InitData()
{
	Drawable::InitData();
	shader = new ModelShader(this->m_vertexShader, this->m_fragmentShader, this->m_tessShader, this->m_geomShader);
	// This part needs to be further abstracted
}

void Model::Draw()
{
	Drawable::Draw();
	shader->Use();
	for (auto& texture : m_textureList) {
		texture->UseTexture();
	}
	shader->setUniformInt("tex1", 0);
	shader->setUniformInt("tex2", 1);
}

void Model::SetTexture(std::string path, GLenum type)
{
	m_textureList.push_back(new Texture2D(path , type));
}
