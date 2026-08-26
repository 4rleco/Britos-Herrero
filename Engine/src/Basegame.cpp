#include "Basegame.h"

#include "Window/Window .h"
#include "Renderer/Renderer.h"

int BaseGame::RunEngine(int width, int height, const char* title)
{
	Window window;

	Renderer renderer = Renderer::GetInstance();

	window.InitWindow(width, height, title);

	renderer.SetWindowContext(window.GetWindow());

	if (!glfwInit())
		return -1;

	while(!window.ShouldClose())
	{
		window.Clear();

		renderer.UpdateBuffers(window.GetWindow());
	}

	renderer.CleanData(window.GetWindow());

	return 0;
}