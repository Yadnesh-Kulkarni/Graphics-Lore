#pragma once
#include "Drawable.h"
#include "Texture2D.h"
class Model : public Drawable
{
public:
	Model();

	~Model();
	void InitData() override;
	void Draw() override;

	void SetVertexShader(std::string path) { m_vertexShader = path; }
	void SetFragmentShader(std::string path) { m_fragmentShader = path; }
	void SetTessShader(std::string path) { m_tessShader = path; }
	void SetGeometryShader(std::string path) { m_geomShader = path; }
	void SetTexture(std::string path, GLenum type);
protected:
	std::string m_vertexShader = "";
	std::string m_fragmentShader = "";
	std::string m_tessShader = "";
	std::string m_geomShader = "";
	std::vector<Texture2D *> m_textureList;
	
};

