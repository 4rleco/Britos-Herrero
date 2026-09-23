#pragma once

#include "Renderer/Renderer.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "EngineAPI.h"

class Entity
{
protected:
	float posX;
	float posY;
	float posZ;

	float r;
	float g;
	float b;
	float a;

	float width;
	float height;


	glm::vec3 scale;
	glm::vec3 rotation;
	glm::vec3 translation;

	glm::mat4 trs;

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

public:
	Entity(float posX, float posY ,float posZ, float width, float height);
	Entity(float posX, float posY ,float posZ, float width, float height,
		float r, float g, float b, float a);
	virtual ~Entity();

	virtual float GetX();
	virtual float GetY();
	virtual float GetZ();

	virtual float GetWidth();
	virtual float GetHeight();

	ENGINE_API void SetScale(float x, float y, float z);
	ENGINE_API void SetRotation(float x, float y, float z);
	ENGINE_API void SetTranslation(float x, float y, float z);

	ENGINE_API void UpdateTRS();

	virtual void Draw();
};