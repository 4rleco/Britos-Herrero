#pragma once

#include "EngineAPI.h"

class ENGINE_API BaseGame
{
public:
	int RunEngine(int width, int height, const char* title);

	virtual void Update();
};