#include "Core.h"
#include "Triangle.h"


Triangle *triangle;

std::vector<Drawable*> models;

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, 800, 600);
}

void render(GLFWwindow* window)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto& model : models)
	{
		model->Draw();
	}
}

int main(int argc, char** argv)
{
	// Initializing GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "The Lore", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, resize);


	std::vector<GLfloat> verts1 = { 0.5f,  0.5f, 0.0f,  // top right
									0.5f, -0.5f, 0.0f,  // bottom right
								   -0.5f, -0.5f, 0.0f,  // bottom left
								   -0.5f,  0.5f, 0.0f   // top left 
	};

	std::vector<GLuint> indices1 = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	triangle = new Triangle();
	triangle->SetVertexShader("vShader.glsl");
	triangle->SetFragmentShader("fShader.glsl");
	triangle->InitData(verts1, indices1);

	models.push_back(triangle);


	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		render(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}