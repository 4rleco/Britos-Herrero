#include "Window.h"

#include <iostream>
#include <exception>

void Window::set(int width, int height, std::string title)
{
	try
	{
		if (!glfwInit())
		{
			windowWidth = width;
			windowHeight = height;

			window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		}
		else
			throw std::exception("The GLFW library is missing");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Window::close()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

/* Cleans all the leftover resources left by the window and the window itself */
void Window::cleanResources()
{
	// Cleans all the resources of the window and destroys it
	glfwDestroyWindow(window);

	// Close the GLFW functions
	glfwTerminate();
}

void Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::update()
{
	glfwSwapBuffers(window);

	glfwPollEvents();
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

int Window::getWidth() const
{
	return windowWidth;
}

int Window::getHeight() const
{
	return windowHeight;
}
