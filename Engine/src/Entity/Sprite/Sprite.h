#pragma once

#include "../Entity2D.h"
#include "TextureImporter.h"
#include "Animation/Animation.h"

class Sprite : public Entity2D
{
protected:
	TextureImporter* textureImporter;
	Animation* animation;

	unsigned int texture;

public:
	Sprite(const char* filepath, float posX, float posY, float posZ,
		float width, float height);
	
	Sprite(const char* filepath, float posX, float posY, float posZ,
		float width, float height, float r, float g, float b, float a);
	
	~Sprite();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;

	virtual Animation* GetAnimation() = 0;
	virtual void SetAnimation(Animation* anim);

	virtual void UpdateAnimation();

	unsigned int GetTexture();
};