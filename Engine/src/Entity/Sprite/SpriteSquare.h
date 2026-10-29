#pragma once

#include "Sprite.h"

#include "EngineAPI.h"

class ENGINE_API SpriteSquare : public Sprite
{
private:
	static const int verticesAmount = 36;
	float vertices[verticesAmount];

	static const int indicesAmount = 6;
	unsigned int indices[indicesAmount];

	int num;

public:
	SpriteSquare();
	
	//sin color
	SpriteSquare(const char* filepath, int num, float posX, float posY, float posZ, float width, float height);
	
	// todos los vértices usan el mismo color y transparencia
	SpriteSquare(const char* filepath, int num, float posX, float posY, float posZ, float width, float height,
		float r, float g, float b, float a);
	~SpriteSquare();

	float* GetVerticesArray();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;

	unsigned int GetIndexAmount();

	void BindTexture();

	void Draw() override;
};