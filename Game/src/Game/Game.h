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
	SpriteSquare* knucles;

	Animation* knuclesCurrentAnim;
	Animation walkRight;
	Animation spin;
	Animation idle;
	Animation wallCollision;


	float rotation;
	float direction;
	float translation;

	float currentPositionX;
	float currentPositionY;

	float previousPositionX;
	float previousPositionY;

	float knuclesSpriteWidth;
	float knuclesSpriteHeight;

public:
	Game();
	~Game();

	void Init() override;
	void DeInit() override;
	void Update() override;
	void Draw();
};