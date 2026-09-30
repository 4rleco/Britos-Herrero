#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{
	float posZ = 0.0f;
	float width = 100.0f;
	float height = 100.0f;

	triangle1 = Triangle(GetWindowWidth() - width * 2, GetWindowHeight() / 2, posZ, width, height,
		1.0f, 0.4f, 0.0f, 1.0f);

	translation = 0.5f;
	direction = 1;
}


void Game::Draw()
{
	triangle1.BindBuffers();
	triangle1.Draw();
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

	Draw();
}
