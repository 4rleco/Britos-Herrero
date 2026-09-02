#include "Basegame.h"

#include "Renderer/Renderer.h"
#include "Window/Window .h"

int BaseGame::RunEngine(int width, int height, const char* title)
{
	Window window;

	window.InitWindow(width, height, title);

	Renderer::GetInstance().SetWindowContext(window.GetWindow());

	Renderer::GetInstance().CheckGlewStatus();

	while(!window.ShouldClose())
	{
		window.Clear();

		Update();

		Renderer::GetInstance().UpdateBuffers(window.GetWindow());
	}

	Renderer::GetInstance().CleanData(window.GetWindow());

	return 0;
}

void BaseGame::Update()
{

}
