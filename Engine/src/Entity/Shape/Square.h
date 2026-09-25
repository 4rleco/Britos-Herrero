#pragma once

#include "Shape.h"
#include "../glm/gtc/type_ptr.hpp"

#include "EngineAPI.h"

class ENGINE_API Square : public Shape
{
private:
	static const int verticesAmount = 28;
	float vertices[verticesAmount];

	static const int indicesAmount = 6;
	unsigned int indices[indicesAmount];

public:
	Square();
	//sin color
	Square(float posX, float posY, float posZ, float width, float height);
	// todos los vértices usan el mismo color y transparencia
	Square(float posX, float posY, float posZ, float width, float height,
		float r, float g, float b, float a);
	~Square();

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