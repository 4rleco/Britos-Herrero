#pragma once

#include "../Entity2D.h"

class Sprite : public Entity2D
{
private:

public:
	Sprite(float posX, float posY, float posZ, float width, float height);
	Sprite(float posX, float posY, float posZ, float width, float height,
		float r, float g, float b, float a);
	~Sprite();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;
};