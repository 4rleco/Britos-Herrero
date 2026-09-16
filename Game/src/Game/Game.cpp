#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::SetTriangle(float x, float y, float z, float width, float height,
	float r, float g, float b, float a)
{
	triangle = Triangle(x, y, z, width, height, r, g , b, a);
}

void Game::Update()
{
	SetTriangle(0.0f, 0.0f, 0.0f, 0.5f, 0.5f,
		0.0f, 0.5f, 0.5f, 1.0f);

	triangle.BindBuffers();
	triangle.Draw();
}
