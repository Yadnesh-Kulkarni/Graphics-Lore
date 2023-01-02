#include "Triangle.h"

Triangle::Triangle()
{
	
}

void Triangle::Initialize()
{
	m_projection = glm::mat4(1.0f);
	m_projection = glm::perspective(glm::radians(45.0f), (float)800.0 / (float)600.0, 0.1f, 100.0f);

	glEnable(GL_DEPTH_TEST);
}

void Triangle::Draw()
{
	Model::Draw();

	m_model = glm::mat4(1.0f);
	m_model = glm::rotate(m_model, (float)glfwGetTime() * glm::radians(-45.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	m_view = glm::mat4(1.0f);
	m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));


	shader->setUniformMat4("projection", m_projection);
	shader->setUniformMat4("view", m_view);
	shader->setUniformMat4("model", m_model);

	glDrawArrays(GL_TRIANGLES, 0, 36);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
