#include "Basegame.h"

#include "Renderer/Renderer.h"
#include "Window/Window .h"

int BaseGame::RunEngine(int width, int height, const char* title)
{
	Renderer renderer = Renderer::GetInstance();

	Window window;

	window.InitWindow(width, height, title);

	renderer.SetWindowContext(window.GetWindow());

	float vertices[6] = {
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	renderer.CheckGlewStatus();

	renderer.BindBuffers(vertices);

	while(!window.ShouldClose())
	{
		window.Clear();

		renderer.Draw();

		renderer.UpdateBuffers(window.GetWindow());
	}

	renderer.CleanData(window.GetWindow());

	return 0;
}