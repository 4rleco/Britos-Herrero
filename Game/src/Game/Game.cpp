#include "Game.h"

Game::Game(Triangle triangle)
{
	this->triangle = triangle;
}

Game::~Game()
{

}

void Game::Update()
{
	triangle.Draw();
}
