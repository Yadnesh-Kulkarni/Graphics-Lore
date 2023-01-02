#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//#include "ShaderSource.h"
//#include "Drawable.h"
//#include "ModelShader.h"
//#include "Triangle.h"

enum Attribute{
	VERTEX_ATTRIB = 0,
	VERTEX_COLOR,
	VERTEX_TEXTURE
};