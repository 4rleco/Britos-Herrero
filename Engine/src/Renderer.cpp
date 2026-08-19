#include "Renderer.h"

void Renderer::setWindowContext(GLFWwindow* window)
{
	glfwMakeContextCurrent(window);
}

/* Switchs the buffers and configurates the next frame (Needed for the correct working of the program) */
void Renderer::updateBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Renderer::drawTriangle(float x, float y, float size)
{
	float finalSize = size / 100.0f;

	glBegin(GL_TRIANGLES);

	glVertex2f(x + finalSize, y - finalSize);
	glVertex2f(x, y + finalSize);
	glVertex2f(x - finalSize, y - finalSize);

	glEnd();
}

void Renderer::cleanWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

/* Cleans all the leftover resources left by the window and the window itself */
void Renderer::cleanData(GLFWwindow* window)
{
	// Cleans all the resources of the window and destroys it
	glfwDestroyWindow(window);

	// Close the GLFW functions
	glfwTerminate();
}
