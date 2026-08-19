#include "Basegame.h"

#include "Window/Window .h"

int BaseGame::RunEngine(int width, int height, const char* title)
{
	Window window;

	window.InitWindow(width, height, title);

	if (!glfwInit())
		return -1;

	while(!window.ShouldClose())
	{
		window.Clear();

		window.Update();
	}

	window.Close();

	return 0;
}