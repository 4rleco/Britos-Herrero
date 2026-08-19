#include "Window.h"
#include "Renderer.h"
#include "Basegame.h"

int BaseGame::RunEngine(int width, int height, const char* title)
{
	Window window;
	Renderer renderer;

	window.set(700, 500, "A");

	renderer.setWindowContext(window.getWindow());

	if (window.getStatus())
	{
		while (!window.shouldClose())
		{
			window.clean();

			renderer.drawTriangle(0, 0, 50);

			renderer.updateBuffers(window.getWindow());
		}

		renderer.cleanData(window.getWindow());
	}

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