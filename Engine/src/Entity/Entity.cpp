#include "Entity.h"

Entity::Entity(float posX, float posY, float posZ, float width, float height)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;

	this->width = width;
	this->height = height;
}

Entity::~Entity()
{

}

float Entity::GetX()
{
	return posX;
}

float Entity::GetY()
{
	return posY;
}

float Entity::GetZ()
{
	return posZ;
}

float Entity::GetWidth()
{
	return width;
}

float Entity::GetHeight()
{
	return height;
}

void Entity::Draw()
{
	
}
