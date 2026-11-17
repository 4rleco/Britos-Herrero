#pragma once

#include "Basegame.h"
#include "Entity/Shape/Triangle.h"
#include "Entity/Shape/Square.h"

#include "Entity/Sprite/SpriteSquare.h"
#include "Entity/Sprite/SpriteTriangle.h"
#include "Input/Input.h"

class Game : public BaseGame
{
private :
	Triangle* triangle1;
	Triangle triangle2;
	
	Square square;

	SpriteSquare* sSquare;
	SpriteSquare* sSquare2;
	Animation walk;
	Animation walkUp;
	Animation idle;

	Animation* currentAnim;

	float rotation;
	float direction;
	float translation;

public:
	Game();
	~Game();

	void Init() override;
	void DeInit() override;
	void Update() override;
	void Draw();
};