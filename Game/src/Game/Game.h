#pragma once

#include "Basegame.h"
#include "Entity/Shape/Triangle.h"
#include "Entity/Shape/Square.h"

class Game : public BaseGame
{
private :
	Triangle triangle1;

	float direction;
	float translation;

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void Draw();
};