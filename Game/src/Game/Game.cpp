#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{
	triangle1 = new Triangle(GetWindowWidth() / 2, GetWindowHeight() / 2, 0.0f,
		200.0f, 200.0f, 0.0f, 0.0f, 1.0f, 0.5f);

	sSquare = new SpriteSquare("LilDallas.jpg", 0, GetWindowWidth() / 2, GetWindowHeight() / 2, 0.0f,
		200.0f, 175.0f);

	rotation = 1.0f;
	translation = 0.1f;
	direction = 2;
}

void Game::DeInit()
{
	delete triangle1;

	delete sSquare;
}


void Game::Draw()
{
	sSquare->Draw();

	triangle1->Draw();
}


void Game::Update()
{
	rotation += 1;

	if (triangle1->GetX() >= GetWindowWidth() + triangle1->GetWidth())
	{
		direction = -1.0f;
	}
	else if (triangle1->GetX() <= 0 - triangle1->GetWidth())
	{
		direction = 1.0f;
	}

	triangle1->SetScale(0.5f, 0.5f, 1.0f);

	triangle1->SetRotation(0.0f, 0.0f, glm::radians(rotation));

	triangle1->SetTranslation(translation * direction, 0.0f, 0.0f);


	Draw();
}
