#pragma once
#include "Drawable.h"
class Model : public Drawable
{
public:
	Model();

	~Model();
	void InitData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices) override;
	void Draw() override;

	void SetVertexShader(std::string path) { m_vertexShader = path; }
	void SetFragmentShader(std::string path) { m_fragmentShader = path; }
	void SetTessShader(std::string path) { m_tessShader = path; }
	void SetGeometryShader(std::string path) { m_geomShader = path; }

protected:
	std::string m_vertexShader = "";
	std::string m_fragmentShader = "";
	std::string m_tessShader = "";
	std::string m_geomShader = "";
};

