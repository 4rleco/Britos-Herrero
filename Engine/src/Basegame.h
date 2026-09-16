#pragma once

#include "EngineAPI.h"

class ENGINE_API BaseGame
{
public:
	BaseGame();
	~BaseGame();

	virtual void Init();

	virtual void Update();

	int RunEngine(int width, int height, const char* title);
};