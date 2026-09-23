#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::Init()
{
	triangle1 = Triangle(0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.5f);

	triangle2 = Triangle(0.0f, 0.0f, 0.0f, 0.5f, 0.5f,
		0.0f, 1.0f, 0.0f, 1.0f);
}


void Game::Draw()
{
	triangle2.BindBuffers();
	triangle2.Draw();
	
	triangle1.BindBuffers();
	triangle1.Draw();
}


void Game::Update()
{
	triangle1.SetScale(0.5f, 0.5f, 0.0f);

	triangle1.SetRotation(0.0f, 0.0f,glm::radians(45.0f));

	triangle1.SetTranslation(0.0f, 0.0f, 0.0f);

	triangle1.UpdateTRS();

	Draw();
}
