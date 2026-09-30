#pragma once

#include "Basegame.h"
#include "Entity/Shape/Triangle.h"
#include "Entity/Shape/Square.h"

class Game : public BaseGame
{
private :
	Triangle triangle1;

	Triangle triangle2;
	Triangle triangle3;

	float direction;
	float translation;

	float rotation1;
	float rotation2;

	float maxRotationSpeed;
	float minRotationSpeed;

	bool rotationReduction1;
	bool rotationReduction2;

public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void Draw();

	void TriangleRotation(float& rotationSpeed, float minRotationSpeed, float maxRotationSpeed, bool& rotationReduction);
};