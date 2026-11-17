#include "Basegame.h"

#include "Renderer/Renderer.h"
#include "Window/Window .h"
#include "Timer/Timer.h"
#include "Input/Input.h"

BaseGame::BaseGame()
{

}

BaseGame::~BaseGame()
{

}

void BaseGame::Init()
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

	Timer::InitClock();

	Input::Init(window.GetWindow());

	Init();

	while (!window.ShouldClose())
	{
		Timer::UpdateDeltaTime();

		Input::Update();

		Renderer::GetInstance().UpdatePollEvents();

		window.Clear();

		Update();

		Renderer::GetInstance().UpdateBuffers(window.GetWindow());
	}

	Renderer::GetInstance().CleanData(window.GetWindow());

	DeInit();

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