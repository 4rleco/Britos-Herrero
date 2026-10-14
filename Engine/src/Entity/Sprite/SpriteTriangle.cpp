#include "SpriteTriangle.h"

SpriteTriangle::SpriteTriangle() :
	Sprite(posX, posY, posZ, width, height)
{

}

SpriteTriangle::SpriteTriangle(float posX, float posY, float posZ, float width, float height) :
	Sprite(posX, posY, posZ, width, height)
{
	material.SetFilepath("Sprite.shader");
	SetMaterial();
	material.SetShader();

	// middle x, y, z	

	// bottom left

	vertices[0] = posX - width;
	vertices[1] = posY - height; // bottom left = x - width, y - height, z
	vertices[2] = posZ;
	// r g b a
	vertices[3] = 1.0f;
	vertices[4] = 1.0f;
	vertices[5] = 1.0f;
	vertices[6] = 1.0f;
	// u v
	vertices[7] = 0.0f;
	vertices[8] = 0.0f;

	// bottom right
	vertices[9] = posX + width;
	vertices[10] = posY - height; // bottom right = x + widht, y -height, z
	vertices[11] = posZ;
	// r g b a
	vertices[12] = 1.0f;
	vertices[13] = 1.0f;
	vertices[14] = 1.0f;
	vertices[15] = 1.0f;
	// u v
	vertices[16] = 1.0f;
	vertices[17] = 0.0f;

	// top
	vertices[18] = posX;
	vertices[19] = posY + height; // top = x, y + height, z
	vertices[20] = posZ;
	// r g b a
	vertices[21] = 1.0f;
	vertices[22] = 1.0f;
	vertices[23] = 1.0f;
	vertices[24] = 1.0f;
	// u v
	vertices[25] = 0.5f;
	vertices[26] = 1.0f;

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
}

SpriteTriangle::SpriteTriangle(float posX, float posY, float posZ, float width, float height,
	float r, float g, float b, float a) : Sprite(posX, posY, posZ, width, height, r, g, b, a)
{
	material.SetFilepath("Sprite.shader");
	SetMaterial();
	material.SetShader();

	// middle x, y, z	

	// bottom left

	vertices[0] = posX - width;
	vertices[1] = posY - height; // bottom left = x - width, y - height, z
	vertices[2] = posZ;
	// r g b a 
	vertices[3] = r;
	vertices[4] = g;
	vertices[5] = b;
	vertices[6] = a;
	// u v
	vertices[7] = 0.0f;
	vertices[8] = 0.0f;

	// bottom right
	vertices[9] = posX + width;
	vertices[10] = posY - height; // bottom right = x + widht, y -height, z
	vertices[11] = posZ;
	// r g b a 
	vertices[12] = r;
	vertices[13] = g;
	vertices[14] = b;
	vertices[15] = a;
	// u v
	vertices[16] = 1.0f;
	vertices[17] = 0.0f;

	// top
	vertices[18] = posX;
	vertices[19] = posY + height; // top = x, y + height, z
	vertices[20] = posZ;
	// r g b a 
	vertices[21] = r;
	vertices[22] = g;
	vertices[23] = b;
	vertices[24] = a;
	// u v
	vertices[25] = 0.5f;
	vertices[26] = 1.0f;

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
}

SpriteTriangle::~SpriteTriangle()
{
	Renderer::GetInstance().DeleteBuffers(VBO, VAO, EBO);
}

float* SpriteTriangle::GetVerticesArray()
{
	return vertices;
}

float SpriteTriangle::GetX()
{
	return posX;
}

float SpriteTriangle::GetY()
{
	return posY;
}

float SpriteTriangle::GetZ()
{
	return posZ;
}

float SpriteTriangle::GetWidth()
{
	return width;
}

float SpriteTriangle::GetHeight()
{
	return height;
}

unsigned int SpriteTriangle::GetIndexAmount()
{
	return 0;
}

void SpriteTriangle::BindBuffers()
{
	Renderer::GetInstance().BindBuffers(vertices, verticesAmount, indices, indicesAmount, VBO, VAO, EBO);
}

void SpriteTriangle::Draw()
{
	material.UseShader();

	unsigned int transformLoc = glGetUniformLocation(material.GetShader(), "trs");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trs));

	unsigned int projViewLoc = glGetUniformLocation(material.GetShader(), "vp");
	glUniformMatrix4fv(projViewLoc, 1, GL_FALSE, glm::value_ptr(Renderer::GetInstance().GetVPMatrix()));

	Renderer::GetInstance().Draw(indicesAmount, VAO);
}
