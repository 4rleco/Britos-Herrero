#include "Window.h"

#include <iostream>
#include <exception>

void Window::set(int width, int height, const char* title)
{
	try
	{
		if (glfwInit())
		{
			windowWidth = width;
			windowHeight = height;

			window = glfwCreateWindow(width, height, title, NULL, NULL);

			hasStarted = true;
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

void Window::clean()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

bool Window::getStatus() const
{
	return hasStarted;
}

int Window::getWidth() const
{
	return windowWidth;
}

int Window::getHeight() const
{
	return windowHeight;
}

GLFWwindow* Window::getWindow() const
{
	return window;
}