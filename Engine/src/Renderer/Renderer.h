#pragma once

#include <GLFW/glfw3.h>

class Renderer
{
private:
	Renderer() = default;

public:
	static Renderer& GetInstance();

	void SetWindowContext(GLFWwindow* window);

	/* Switchs the buffers and configurates the next frame (Needed for the correct working of the program) */
	void UpdateBuffers(GLFWwindow* window);

	void CleanWindow();

	/* Cleans all the resources left by the window (Use it when the program ends) */
	void CleanData(GLFWwindow* window);
};