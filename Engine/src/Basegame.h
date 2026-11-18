#pragma once

#include "Renderer/Renderer.h"
#include "Window/Window .h"
#include "CollisionManager/CollisionManager.h"

#include "EngineAPI.h"

class ENGINE_API BaseGame
{
protected:
	int windowWidth;
	int windowHeight;

	CollisionManager collisionManager;

public:
	BaseGame();
	~BaseGame();

	int GetWindowWidth();
	int GetWindowHeight();

	virtual void Init();
	virtual void DeInit() = 0;

	virtual void Update() = 0;

	int RunEngine(int width, int height, const char* title);
};