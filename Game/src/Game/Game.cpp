#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::Init()
{
	triangle = Triangle(0.0f, 0.0f, 0.0f, 0.5f, 0.5f,
		0.0f, 0.5f, 0.5f, 1.0f);
}


void Game::Draw()
{
	triangle.BindBuffers();
	triangle.Draw();
}


void Game::Update()
{
	Draw();
}
