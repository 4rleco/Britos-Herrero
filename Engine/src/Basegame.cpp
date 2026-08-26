#include "Basegame.h"

#include "Renderer/Renderer.h"
#include "Window/Window .h"

int BaseGame::RunEngine(int width, int height, const char* title)
{
	Window window;

	window.InitWindow(width, height, title);

	float vertices[6] = {
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	Renderer::GetInstance().SetWindowContext(window.GetWindow());

	Renderer::GetInstance().CheckGlewStatus();

	Renderer::GetInstance().BindBuffers(vertices);

	while(!window.ShouldClose())
	{
		std::cout << "entra" << std::endl;

		window.Clear();

		Renderer::GetInstance().Draw();

		Renderer::GetInstance().UpdateBuffers(window.GetWindow());
	}

	Renderer::GetInstance().CleanData(window.GetWindow());

	std::cout << "sale" << std::endl;

	return 0;
}