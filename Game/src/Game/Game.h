#pragma once

#include "Basegame.h"
#include "Entity/Shape/Triangle.h"

class Game : public BaseGame
{
private :
	Triangle triangle;

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void Draw();
};