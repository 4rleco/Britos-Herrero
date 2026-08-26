#include "Renderer.h"

Renderer& Renderer::GetInstance()
{
	static Renderer instance;
	return instance;
}

void Renderer::SetWindowContext(GLFWwindow* window)
{
	glfwMakeContextCurrent(window);
}

/* Switchs the buffers and configurates the next frame (Needed for the correct working of the program) */
void Renderer::UpdateBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);

	glfwPollEvents();
}

void Renderer::CleanWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

/* Cleans all the leftover resources left by the window and the window itself */
void Renderer::CleanData(GLFWwindow* window)
{
	// Cleans all the resources of the window and destroys it
	glfwDestroyWindow(window);

	// Close the GLFW functions
	glfwTerminate();
}