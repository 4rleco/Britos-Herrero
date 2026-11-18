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

	sSquare = new SpriteSquare("pokemon.png", 0, GetWindowWidth() / 2, GetWindowHeight() / 2, 0.0f,
		200.0f, 175.0f);

	sSquare2 = new SpriteSquare("LilDallas.jpg", 0, 50, 150, 0.0f,
		50.0f, 50.0f);

	walkLeft.AddFrames(0, 128, 64, 64, 256, 256, 1, 4);
	walkRight.AddFrames(0, 64, 64, 64, 256, 256, 1, 4);


	idle.AddFrame(0, 128, 64, 64, 256, 256, 1);

	rotation = 1.0f;
	translation = 1.0f;
	direction = 2;

	currentAnim = &idle;

	sSquare->SetAnimation(currentAnim);
	//sSquare2->SetAnimation(&walkUp);

	currentPositionX = sSquare->GetX();
	currentPositionY = sSquare->GetY();
}

void Game::DeInit()
{
	delete triangle1;

	delete sSquare;
	delete sSquare2;
}


void Game::Draw()
{
	sSquare->Draw();
	sSquare2->Draw();

	triangle1->Draw();
}


void Game::Update()
{
	rotation += 1;

	//shape
	//if (triangle1->GetX() >= GetWindowWidth() + triangle1->GetWidth())
	//{
	//	direction = -1.0f;
	//}
	//else if (triangle1->GetX() <= 0 - triangle1->GetWidth())
	//{
	//	direction = 1.0f;
	//}
	//
	//triangle1->SetScale(0.5f, 0.5f, 1.0f);
	//
	//triangle1->SetRotation(0.0f, 0.0f, glm::radians(rotation));
	//
	//triangle1->SetTranslation(translation * direction, 0.0f, 0.0f);
	//

	// Animation


	previousPositionX = sSquare->GetX();
	previousPositionY = sSquare->GetY();

	if (Input::IsKeyPressed(Key::A) && currentAnim != &walkLeft)
	{
		currentAnim = &walkLeft;

		direction = -1;

		sSquare->SetAnimation(currentAnim);
	}

	if (Input::IsKeyPressed(Key::D) && currentAnim != &walkRight)
	{
		currentAnim = &walkRight;

		direction = 1;

		sSquare->SetAnimation(currentAnim);
	}

	if ((Input::IsKeyReleased(Key::A) || Input::IsKeyReleased(Key::D)) && currentAnim != &idle)
	{
		currentAnim = &idle;

		direction = 0;

		sSquare->SetAnimation(currentAnim);
	}

	sSquare->SetTranslation(translation * direction, 0.0f, 0.0f);

	currentPositionX = sSquare->GetX();
	currentPositionY = sSquare->GetY();

	if (collisionManager.CollisionCheck(sSquare, sSquare2))
	{
		sSquare->SetX(previousPositionX);
		sSquare->SetY(previousPositionY);

		currentPositionX = previousPositionX;
		currentPositionY = previousPositionY;
	}
	//sSquare->GetAnimation()->Update();

	sSquare->UpdateAnimation();
	//sSquare2->UpdateAnimation();
	//


	Draw();
}
