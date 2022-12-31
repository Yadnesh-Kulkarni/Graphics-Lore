#pragma once

// Default Shaders

const char* vertexShaderSourceCode =
"#version 450 core"\
"\n"\
"in vec4 vPosition;"\
"void main(void)"\
"{"\
"gl_Position = vPosition;\n"\
"}\0";

const char* fragmentShaderSourceCode =
"#version 450 core"\
"\n"\
"out vec4 FragColor;"\
"uniform vec4 ourColor;"\
"void main()"\
"{"\
"FragColor = ourColor;"
"}\0";
