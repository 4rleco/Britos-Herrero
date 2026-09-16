#include "Basegame.h"

#include "Renderer/Renderer.h"
#include "Window/Window .h"

BaseGame::BaseGame()
{

}

BaseGame::~BaseGame()
{

}

void BaseGame::Init()
{

}

void BaseGame::Update()
{

}

int BaseGame::RunEngine(int width, int height, const char* title)
{
	Window window;

	window.InitWindow(width, height, title);

	Renderer::GetInstance().SetWindowContext(window.GetWindow());

	Renderer::GetInstance().CheckGlewStatus();

	Init();

	while(!window.ShouldClose())
	{
		window.Clear();

		Update();

		Renderer::GetInstance().UpdateBuffers(window.GetWindow());
	}

	Renderer::GetInstance().CleanData(window.GetWindow());

	return 0;
}