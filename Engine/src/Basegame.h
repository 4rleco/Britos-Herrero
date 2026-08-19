#pragma once

#include "EngineAPI.h"

#include "Window/Window .h"

class BaseGame
{
public:
	ENGINE_API int RunEngine(int width, int height, const char* title);
};