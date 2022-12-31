#include "Triangle.h"

Triangle::Triangle()
{

}

void Triangle::Draw()
{
	Model::Draw();

	float timeValue = glfwGetTime();
	float redValue = (sin(timeValue) / 2.0f) + 0.5f;
	shader->setUniformVec4("color", redValue, 0.0f, 0.0f, 0.0f);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
