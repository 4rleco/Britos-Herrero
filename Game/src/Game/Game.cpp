#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::SetTriangle(float x, float y, float z, float width, float height)
{
	triangle = Triangle(x, y, z, width, height);
}

void Game::Update()
{
	SetTriangle(0.0f, 0.0f, 0.0f, 0.5f, 0.5f);

	triangle.BindBuffers();
	triangle.Draw();
}
