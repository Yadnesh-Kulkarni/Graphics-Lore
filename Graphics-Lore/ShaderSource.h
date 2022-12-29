#pragma once

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
"void main()"\
"{"\
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
"}\0";
