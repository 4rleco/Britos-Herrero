#include "Window/Window .h"

#include <iostream>

#include <exception>

using namespace std;

Window::Window()
{
	window = nullptr;

	windowWidth = 0;
	windowHeight = 0;
}

Window::~Window()
{

}

void Window::InitWindow(int width, int height, const char* title)
{
	try
	{
		if (glfwInit())
		{
			windowWidth = width;
			windowHeight = height;

			window = glfwCreateWindow(width, height, title, NULL, NULL);
		}
		else
			throw std::exception("The GLFW library is missing");
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Window::Close()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void Window::CleanResources()
{
	glfwDestroyWindow(window);

	glfwTerminate();
}

void Window::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::Update()
{
	glfwPollEvents();

	glfwSwapBuffers(window);
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

int Window::GetWidth() const
{
	return windowWidth;
}

int Window::GetHeight() const
{
	return windowHeight;
}