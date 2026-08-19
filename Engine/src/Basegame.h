#pragma once

#include <string>

#include "EngineAPI.h"

ENGINE_API class BaseGame
{
public:
	ENGINE_API int RunEngine(int width, int height, std::string title);

	void setWindow(int width, int height, std::string title);

};