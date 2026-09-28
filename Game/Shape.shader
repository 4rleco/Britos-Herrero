#vertex shader

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

out vec4 ourColor;

uniform mat4 trs;
uniform mat4 proj;

void main()
{
    gl_Position = proj * trs * vec4(aPos, 1.0);
    ourColor = aColor;
}

#fragment shader

#version 330 core
out vec4 FragColor;
in vec4 ourColor;

void main()
{
    FragColor = ourColor;
} 