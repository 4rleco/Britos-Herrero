#include <GLFW/glfw3.h>

#include "Window.h"
#include "Basegame.h"

int BaseGame::RunEngine(int width, int height, std::string title)
{
	Window window;

	window.set(width, height, title);

	if (!window.shouldClose())
	{
		window.clear();

		window.update();
	}

	window.cleanResources();

	/*GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (!window)
	{
		glfwTerminate();

		return -1;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{

		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(window);


		glfwPollEvents();
	}

	glfwTerminate();*/

	return 0;
}