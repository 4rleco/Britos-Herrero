#pragma once

#include "Basegame.h"
#include "Entity/Shape/Triangle.h"
#include "Entity/Shape/Square.h"

#include "Entity/Sprite/SpriteSquare.h"
#include "Entity/Sprite/SpriteTriangle.h"

class Game : public BaseGame
{
private :
	Triangle triangle1;
	Triangle triangle2;
	
	Square square;
	SpriteSquare sSquare;

	float rotation;
	float direction;
	float translation;

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void Draw();
};