#include "Entity2D.h"

Entity2D::Entity2D(float posX, float posY, float posZ, float width, float height) : 
	Entity (posX, posY, posZ, width, height)
{

}

Entity2D::~Entity2D()
{

}

float Entity2D::GetX()
{
	return posX;
}

float Entity2D::GetY()
{
	return 0.0f;
}

float Entity2D::GetZ()
{
	return 0.0f;
}

float Entity2D::GetWidth()
{
	return 0.0f;
}

float Entity2D::GetHeight()
{
	return 0.0f;
}

void Entity2D::Draw()
{
	
}
