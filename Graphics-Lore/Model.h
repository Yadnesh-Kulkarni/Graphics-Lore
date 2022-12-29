#pragma once
#include "Drawable.h"
class Model : public Drawable
{
public:
	Model();
	~Model();
	void InitData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices) override;
	void Draw() override;
	
};

