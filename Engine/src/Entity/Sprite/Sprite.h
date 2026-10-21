#pragma once

#include "../Entity2D.h"
#include "TextureImporter.h"

#include <iostream>

class Sprite : public Entity2D
{
protected:
	TextureImporter textureImporter;
	std::string filepath;

	unsigned int texture;

public:
	Sprite(std::string filepath, float posX, float posY, float posZ,
		float width, float height);
	
	Sprite(std::string filepath, float posX, float posY, float posZ, 
		float width, float height, float r, float g, float b, float a);
	
	~Sprite();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;

	std::string GetFilepath();
	unsigned int GetTexture();
};