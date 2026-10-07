#pragma once

#include "Sprite.h"
#include "../glm/gtc/type_ptr.hpp"

#include "EngineAPI.h"

class ENGINE_API SpriteTriangle : public Sprite
{
private:
	static const int verticesAmount = 21;
	float vertices[verticesAmount];

	static const int indicesAmount = 3;
	unsigned int indices[indicesAmount];

public:
	SpriteTriangle();
	//sin color
	SpriteTriangle(float posX, float posY, float posZ, float width, float height);
	// todos los vértices usan el mismo color y transparencia
	SpriteTriangle(float posX, float posY, float posZ, float width, float height,
		float r, float g, float b, float a);
	~SpriteTriangle();

	float* GetVerticesArray();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;

	unsigned int GetIndexAmount();

	void BindBuffers();

	void Draw() override;
};