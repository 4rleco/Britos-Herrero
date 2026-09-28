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

	rotation = 0.5f;
	translation = 0.01f;
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
	rotation += 0.01;
	translation += 0.1;

	triangle1.SetScale(0.5f, 0.5f, 1.0f);

	//triangle1.SetRotation(0.0f, 0.0f, glm::radians(45.0f ));

	cout << triangle1.GetX() + triangle1.GetWidth() << endl;

	if (triangle1.GetX() + triangle1.GetWidth() / 2 >= GetWindowWidth())
	{
		translation *= -1;
	}
	if (triangle1.GetX() - triangle1.GetWidth() / 2 <= 0)
	{
		translation = 1;
	}

	triangle1.SetTranslation(translation, 0.0f, 0.0f);

	triangle1.UpdateTRS();

	Draw();
}
