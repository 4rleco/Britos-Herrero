#include "Basegame.h"

#include "Renderer/Renderer.h"
#include "Window/Window .h"

#include "Entity/Shape/Triangle.h"

int BaseGame::RunEngine(int width, int height, const char* title)
{
	Window window;

	window.InitWindow(width, height, title);

	Triangle triangle = Triangle(0.0f, 0.0f, 0.0f, 0.5f, 0.5f);

	Renderer::GetInstance().SetWindowContext(window.GetWindow());

	Renderer::GetInstance().CheckGlewStatus();

	Renderer::GetInstance().BindBuffers();

	while(!window.ShouldClose())
	{
		window.Clear();

		triangle.Draw();

		Renderer::GetInstance().UpdateBuffers(window.GetWindow());
	}

	Renderer::GetInstance().CleanData(window.GetWindow());

	return 0;
}