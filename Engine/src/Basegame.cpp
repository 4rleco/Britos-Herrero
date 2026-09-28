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
	Window window = Window(width, height, title);

	windowWidth = window.GetWidth();
	windowHeight = window.GetHeight();

	Renderer::GetInstance().SetWindowContext(window.GetWindow());

	Renderer::GetInstance().CheckGlewStatus();

	Renderer::GetInstance().SetVPMatrix(window.GetWidth(), window.GetHeight());

	Init();

	while (!window.ShouldClose())
	{
		window.Clear();

		Update();

		Renderer::GetInstance().UpdateBuffers(window.GetWindow());
	}

	Renderer::GetInstance().CleanData(window.GetWindow());

	return 0;
}


int BaseGame::GetWindowWidth()
{
	return windowWidth;
}

int BaseGame::GetWindowHeight()
{
	return windowHeight;
}