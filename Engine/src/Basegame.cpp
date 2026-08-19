#include "Basegame.h"

#include "Window/Window .h"

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