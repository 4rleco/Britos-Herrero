#pragma once

#include "../Entity2D.h"
//#include "TextureImporter.h"

class Sprite : public Entity2D
{
protected:
	//TextureImporter textureImporter;
	const char* filepath;

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

	std::string GetFilepath();
	unsigned int GetTexture();
};