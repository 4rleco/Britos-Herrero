#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{
	float posZ1 = 0.0f;
	float width1 = 100.0f;
	float height1 = 100.0f;

	triangle1 = Triangle(GetWindowWidth() - width1 * 2, GetWindowHeight() / 2, posZ1, width1, height1,
		1.0f, 0.4f, 0.0f, 1.0f);

	translation = 0.5f;
	direction = 1;

	float posZ2 = 0.0f;
	float width2 = 50.0f;
	float height2 = 50.0f;

	triangle2 = Triangle(0 + width2 * 2, GetWindowHeight() / 2, posZ2, width2, height2,
		1.0f, 0.0f, 0.0f, 1.0f);

	triangle3 = Triangle(0 + width2 * 2, GetWindowHeight() / 2 - 20, posZ2, width2, height2,
		1.0f, 0.0f, 0.0f, 1.0f);

	maxRotationSpeed = 500;
	minRotationSpeed = 1;

	rotation1 = 1;
	rotation2 = 1;

	rotationReduction1 = false;
	rotationReduction2 = false;
}


void Game::Draw()
{
	triangle3.BindBuffers();
	triangle3.Draw();

	triangle2.BindBuffers();
	triangle2.Draw();

	triangle1.BindBuffers();
	triangle1.Draw();
}

void Game::TriangleRotation(float& rotationSpeed, float minRotationSpeed, float maxRotationSpeed, bool& rotationReduction)
{
	float speedIncrease = 0.5;

	if (rotationSpeed < maxRotationSpeed && !rotationReduction)
		rotationSpeed += speedIncrease;

	if (rotationSpeed > minRotationSpeed && rotationReduction)
		rotationSpeed -= speedIncrease;

	if (rotationSpeed >= maxRotationSpeed)
		rotationReduction = true;

	if (rotationSpeed <= minRotationSpeed)
		rotationReduction = false;
}


void Game::Update()
{
	if (triangle1.GetY() >= GetWindowHeight() - triangle1.GetHeight())
	{
		triangle1.SetRotation(0.0f, 0.0f, glm::radians(-180.0f));
		direction = -1.0f;
	}
	else if (triangle1.GetY() <= 0 + triangle1.GetHeight())
	{
		triangle1.SetRotation(0.0f, 0.0f, glm::radians(0.0f));
		direction = 1.0f;
	}

	triangle1.SetTranslation(0.0f, translation * direction, 0.0f);

	triangle1.UpdateTRS();

	TriangleRotation(rotation1, minRotationSpeed, maxRotationSpeed, rotationReduction1);
	TriangleRotation(rotation2, minRotationSpeed, maxRotationSpeed, rotationReduction2);

	triangle2.SetRotation(0.0f, 0.0f, glm::radians(rotation1));
	triangle2.UpdateTRS();

	triangle3.SetRotation(0.0f, 0.0f, glm::radians(-180 - rotation2));
	triangle3.UpdateTRS();

	Draw();
}
