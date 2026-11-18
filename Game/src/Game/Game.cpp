#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{
	knucles = new SpriteSquare("Knuckles_Sprite_Sheet.png", 0, 200, 200, 0.0f,
		100.0f, 100.0f);

	rock = new SpriteSquare("Rock.png", 0, 500, 200, 0.0f,
		50, 50);

	knuclesSpriteWidth = 646;
	knuclesSpriteHeight = 473;

	idle.AddFrame(0, 473, 35, 35, 646, 473, 1);
	walkRight.AddFrames(0, 392, 40.5f, 35, knuclesSpriteWidth, knuclesSpriteHeight, 1, 8);
	spin.AddFrames(0, 307.8f, 32.5f, 35, knuclesSpriteWidth, knuclesSpriteHeight, 0.7, 6);
	wallCollision.AddFrames(422, 347, 35, 35, knuclesSpriteWidth, knuclesSpriteHeight, 1, 4);


	translation = 1.0f;
	direction = 0;

	knuclesCurrentAnim = &idle;

	knucles->SetAnimation(knuclesCurrentAnim);

	currentPositionX = knucles->GetX();
	currentPositionY = knucles->GetY();
}

void Game::DeInit()
{
	delete knucles;
}


void Game::Draw()
{
	knucles->Draw();
}


void Game::Update()
{
	// Animation


	previousPositionX = knucles->GetX();
	previousPositionY = knucles->GetY();

	/*if (Input::IsKeyPressed(Key::A) && currentAnim != &walkLeft)
	{
		currentAnim = &walkLeft;

		direction = -1;

		sSquare->SetAnimation(currentAnim);
	}*/

	if (Input::IsKeyPressed(Key::Z))
	{
		rock->SetAnimation(&staticRock);
	}

	if (Input::IsKeyDown(Key::D) && knuclesCurrentAnim != &walkRight)
	{
		knuclesCurrentAnim = &walkRight;

		direction = 1;

		knucles->SetAnimation(knuclesCurrentAnim);
	}

	if (Input::IsKeyDown(Key::E) && knuclesCurrentAnim != &spin)
	{
		knuclesCurrentAnim = &spin;

		knucles->SetAnimation(knuclesCurrentAnim);
	}

	if ((Input::IsKeyReleased(Key::D) || Input::IsKeyReleased(Key::E)) && 
		knuclesCurrentAnim != &idle && knuclesCurrentAnim != &wallCollision)
	{
		knuclesCurrentAnim = &idle;

		direction = 0;

		knucles->SetAnimation(knuclesCurrentAnim);
	}
	
	knucles->SetTranslation(translation * direction, 0.0f, 0.0f);

	currentPositionX = knucles->GetX();
	currentPositionY = knucles->GetY();

	if (collisionManager.CollisionCheck(sSquare, sSquare2))
	{
		sSquare->SetX(previousPositionX);
		sSquare->SetY(previousPositionY);

		currentPositionX = previousPositionX;
		currentPositionY = previousPositionY;
	}
	//sSquare->GetAnimation()->Update();



	knucles->UpdateAnimation();
	//sSquare2->UpdateAnimation();
	//


	Draw();
}
