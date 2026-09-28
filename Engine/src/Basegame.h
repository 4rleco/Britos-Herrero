#pragma once

#include "Renderer/Renderer.h"
#include "Window/Window .h"

#include "EngineAPI.h"

class ENGINE_API BaseGame
{
private:
	int windowWidth;
	int windowHeight;

public:
	BaseGame();
	~BaseGame();

	int GetWindowWidth();
	int GetWindowHeight();

	virtual void Init();

	virtual void Update();

	int RunEngine(int width, int height, const char* title);
};