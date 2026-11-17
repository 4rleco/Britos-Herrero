#include "Sprite.h"

Sprite::Sprite(const char* filepath, float posX, float posY, float posZ,
	float width, float height) :
	Entity2D(posX, posY, posZ, width, height)
{
	animation = new Animation();
}

Sprite::Sprite(const char* filepath, float posX, float posY, float posZ,
	float width, float height,
	float r, float g, float b, float a) :Entity2D(posX, posY, posZ, width, height, r, g, b, a)
{
	animation = new Animation();
}

Sprite::~Sprite()
{
	delete textureImporter;
	delete animation;
}

float Sprite::GetX()
{
	return posX;
}

float Sprite::GetY()
{
	return 0.0f;
}

float Sprite::GetZ()
{
	return 0.0f;
}

float Sprite::GetWidth()
{
	return 0.0f;
}

float Sprite::GetHeight()
{
	return 0.0f;
}

void Sprite::SetAnimation(Animation* anim)
{

}

void Sprite::UpdateAnimation()
{

}

unsigned int Sprite::GetTexture()
{
	return texture;
}
