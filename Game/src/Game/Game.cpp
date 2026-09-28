#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{
	triangle1 = Triangle(400.0f, 320.0f, 0.0f, 200.0f, 200.0f,
		0.0f, 0.0f, 1.0f, 0.5f);

	triangle2 = Triangle(400.0f, 320.0f, 0.0f, 100.0f, 100.0f,
		0.0f, 1.0f, 0.0f, 1.0f);

	square = Square(400, 320, 0.0f, 100.0f, 100.0f,
		1.0f, 0.0f, 0.0f, 1.0f);

	rotation = 1.0f;
	translation = 0.1f;
	direction = 2;
}


void Game::Draw()
{

	square.BindBuffers();
	square.Draw();

	triangle2.BindBuffers();
	triangle2.Draw();

	triangle1.BindBuffers();
	triangle1.Draw();
}


void Game::Update()
{
	rotation += 1;

	triangle1.SetScale(0.5f, 0.5f, 1.0f);

	cout << triangle1.GetY() << endl;

	triangle1.SetRotation(0.0f, 0.0f, glm::radians(-180.0f * 1));

	if (triangle1.GetY() >= GetWindowHeight() + triangle1.GetHeight())
	{
		triangle1.SetRotation(0.0f, 0.0f, glm::radians(-180.0f * 1));
		direction = -1.0f;
	}
	else if (triangle1.GetY() <= 0 - triangle1.GetHeight())
	{
		triangle1.SetRotation(0.0f, 0.0f, glm::radians(180.0f));
		direction = 1.0f;
	}

	triangle1.SetTranslation(0.0f, translation * direction, 0.0f);

	//cout << triangle1.GetX() << endl;

	//triangle1.SetRotation(0.0f, 0.0f, glm::radians(rotation));

	//triangle1.SetTranslation(translation * direction, 0.0f, 0.0f);

	triangle1.UpdateTRS();

	Draw();
}
