#pragma once

#include "Basegame.h"
#include "Entity/Shape/Triangle.h"

class Game : public BaseGame
{
private:
	Triangle triangle = Triangle();

public:
	Game();
	~Game();

	void SetTriangle(float x, float y, float z, float width, float height);

	void Update() override;
};