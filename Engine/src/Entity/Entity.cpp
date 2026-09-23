#include "Entity.h"

Entity::Entity(float posX, float posY, float posZ, float width, float height)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;

	this->width = width;
	this->height = height;

	scale = glm::vec3(1.0f);
	rotation  = glm::vec3(1.0f);
	translation = glm::vec3(1.0f);

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

	scale = glm::vec3(1.0f);
	rotation = glm::vec3(1.0f);
	translation = glm::vec3(1.0f);

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
	scale = glm::vec3(x, y, z);
}

void Entity::SetRotation(float x, float y, float z)
{
	rotation = glm::vec3(x, y, z);
}

void Entity::SetTranslation(float x, float y, float z)
{
	translation = glm::vec3(x, y, z);
}

void Entity::UpdateTRS()
{
	trs = glm::mat4(1.0f);

	trs = glm::translate(trs, translation);

	trs = glm::rotate(trs, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));

	trs = glm::rotate(trs, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));

	trs = glm::rotate(trs, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

	trs = glm::scale(trs, scale);
}

void Entity::Draw()
{

}
