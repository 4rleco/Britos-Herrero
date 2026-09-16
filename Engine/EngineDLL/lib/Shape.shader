#vertex shader

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

out vec4 ourColor;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    ourColor = aColor;
}

#fragment shader

#version 330 core
out vec4 FragColor;
in vec4 ourColor;

void main()
{
   FragColor = vec4(1.0, 0.0, 0.0, 0.1);
} 