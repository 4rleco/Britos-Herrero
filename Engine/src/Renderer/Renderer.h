#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Renderer
{
private:
	unsigned int VBO;
	unsigned int VAO;
	Renderer() = default;

public:
	static Renderer& GetInstance();

	// check if glew loaded correctly
	void CheckGlewStatus();

	void SetWindowContext(GLFWwindow* window);

	// binds and generete vertex buffers
	void BindBuffers();

	void Draw(float* vertices);

	// Switchs the buffers and configurates the next frame (Needed for the correct working of the program)
	void UpdateBuffers(GLFWwindow* window);

	void CleanWindow();

	// Cleans all the resources left by the window (Use it when the program ends)
	void CleanData(GLFWwindow* window);
};