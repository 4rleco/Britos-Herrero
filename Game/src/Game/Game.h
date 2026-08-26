#pragma once

#include "Basegame.h"
#include "Entity/Shape/Triangle.h"

class Game : public BaseGame
{
private:
	Triangle triangle = Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

public:
	Game(Triangle triangle);
	~Game();

	void Update() override;
};