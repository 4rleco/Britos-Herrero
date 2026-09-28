#include "Entity.h"

Entity::Entity(float posX, float posY, float posZ, float width, float height)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;

	this->width = width;
	this->height = height;

	initialPivot = glm::vec3(posX, posY, posZ);

	scale = glm::mat4(1.0f);
	rotation = glm::mat4(1.0f);
	translation = glm::mat4(1.0f);

	trs = glm::mat4(1.0f);
}

Entity::Entity(float posX, float posY, float posZ, float width, float height,
	float r, float g, float b, float a)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;

	this->width = width;
	this->height = height;

	initialPivot = glm::vec3(posX, posY, posZ);

	scale = glm::mat4(1.0f);
	rotation = glm::mat4(1.0f);
	translation = glm::mat4(1.0f);

	trs = glm::mat4(1.0f);
}

Entity::~Entity()
{
	Renderer::GetInstance().DeleteBuffers(VBO, VAO, EBO);
}

float Entity::GetX()
{
	return posX;
}

float Entity::GetY()
{
	return posY;
}

float Entity::GetZ()
{
	return posZ;
}

float Entity::GetWidth()
{
	return width;
}

float Entity::GetHeight()
{
	return height;
}

void Entity::SetScale(float x, float y, float z)
{
	scale = glm::scale(glm::mat4(1.0f), glm::vec3(x, y, z));
}

void Entity::SetRotation(float x, float y, float z)
{
	rotation = glm::mat4(1.0f);

	rotation = glm::rotate(rotation, x, glm::vec3(1.0f, 0.0f, 0.0f));

	rotation = glm::rotate(rotation, y, glm::vec3(0.0f, 1.0f, 0.0f));

	rotation = glm::rotate(rotation, z, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Entity::SetTranslation(float x, float y, float z)
{
	translation = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
}

void Entity::UpdateTRS()
{
	posX += translation[3].x;
	posY += translation[3].y;
	posZ += translation[3].z;

	glm::vec3 currentPivot(posX, posY, posZ);

	glm::mat4 T_current = glm::translate(
		glm::mat4(1.0f),
		currentPivot
	);

	glm::mat4 T_initial = glm::translate(
		glm::mat4(1.0f),
		-initialPivot
	);

	trs = T_current * rotation * scale * T_initial;
}

void Entity::Draw()
{

}