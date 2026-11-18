#pragma once

#include "Sprite.h"
#include "../glm/gtc/type_ptr.hpp"

#include "EngineAPI.h"

class ENGINE_API SpriteTriangle : public Sprite
{
private:
	static const int verticesAmount = 27;
	float vertices[verticesAmount];

	static const int indicesAmount = 3;
	unsigned int indices[indicesAmount];

	int num;

public:
	SpriteTriangle();
	//sin color
	SpriteTriangle(const char* filepath, float posX, float posY, float posZ, float width, float height);
	// todos los vértices usan el mismo color y transparencia
	SpriteTriangle(const char* filepath, float posX, float posY, float posZ, float width, float height,
		float r, float g, float b, float a);
	~SpriteTriangle();

	float* GetVerticesArray();

	void SetX(float x) override;
	float GetX() override;
	void SetY(float y) override;
	float GetY() override;
	void SetZ(float z) override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;

	unsigned int GetIndexAmount();

	Animation* GetAnimation() override;
	void SetAnimation(Animation* anim) override;

	void UpdateAnimation() override;

	void BindTexture();

	void Draw() override;
};