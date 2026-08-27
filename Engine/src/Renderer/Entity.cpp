#include "Entity.h"

void Entity::setPosX(int x)
{
	this->x = x;
}

void Entity::setPosY(int y)
{
	this->y = y;
}

void Entity::setRotation(int rotation)
{
	this->rotation = rotation;
}

int Entity::getPosX() const
{
	return x;
}

int Entity::getPosY() const
{
	return y;
}

int Entity::getRotation() const
{
	return rotation;
}
