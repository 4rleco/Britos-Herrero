#pragma once

#include "Renderer/Renderer.h"

class Entity
{
protected:
	float posX;
	float posY;
	float posZ;

	float r;
	float g;
	float b;

	float width;
	float height;

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

public:
	Entity(float posX, float posY ,float posZ, float width, float height);
	virtual ~Entity();

	virtual float GetX();
	virtual float GetY();
	virtual float GetZ();

	virtual float GetWidth();
	virtual float GetHeight();

	virtual void Draw();
};