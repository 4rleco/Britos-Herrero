#include "SpriteSquare.h"

SpriteSquare::SpriteSquare() :
	Sprite(posX, posY, posZ, width, height)
{

}

SpriteSquare::SpriteSquare(float posX, float posY, float posZ, float width, float height) :
	Sprite(posX, posY, posZ, width, height)
{
	material.SetFilepath("Sprtie.shader");
	SetMaterial();
	material.SetShader();

	// middle x, y, z	

	// bottom left

	vertices[0] = posX - width;
	vertices[1] = posY - height; // bottom left = x - width, y - height, z
	vertices[2] = posZ;
	vertices[3] = 1.0f;
	vertices[4] = 1.0f;
	vertices[5] = 1.0f;
	vertices[6] = 1.0f;

	// bottom right
	vertices[7] = posX + width;
	vertices[8] = posY - height; // bottom right = x + widht, y -height, z
	vertices[9] = posZ;
	vertices[10] = 1.0f;
	vertices[11] = 1.0f;
	vertices[12] = 1.0f;
	vertices[13] = 1.0f;

	// top left
	vertices[14] = posX - width;
	vertices[15] = posY + height; // top right = x - width, y + height, z
	vertices[16] = posZ;
	vertices[17] = 1.0f;
	vertices[18] = 1.0f;
	vertices[19] = 1.0f;
	vertices[20] = 1.0f;

	// top right
	vertices[21] = posX + width;
	vertices[22] = posY + height; // top = x + width, y + height, z
	vertices[23] = posZ;
	vertices[24] = 1.0f;
	vertices[25] = 1.0f;
	vertices[26] = 1.0f;
	vertices[27] = 1.0f;
	
	// first triangle
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 3;
	
	// Second triangle
	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;
}

SpriteSquare::SpriteSquare(float posX, float posY, float posZ, float width, float height,
	float r, float g, float b, float a) : Sprite(posX, posY, posZ, width, height, r, g, b, a)
{
	material.SetFilepath("Sprtie.shader");
	SetMaterial();
	material.SetShader();

	// middle x, y, z	

	// bottom left

	vertices[0] = posX - width;
	vertices[1] = posY - height; // bottom left = x - width, y - height, z
	vertices[2] = posZ;
	vertices[3] = r;
	vertices[4] = g;
	vertices[5] = b;
	vertices[6] = a;

	// bottom right
	vertices[7] = posX + width;
	vertices[8] = posY - height; // bottom right = x + widht, y -height, z
	vertices[9] = posZ;
	vertices[10] = r;
	vertices[11] = g;
	vertices[12] = b;
	vertices[13] = a;

	// top left
	vertices[14] = posX - width;
	vertices[15] = posY + height; // top right = x - width, y + height, z
	vertices[16] = posZ;
	vertices[17] = r;
	vertices[18] = g;
	vertices[19] = b;
	vertices[20] = a;

	// top right
	vertices[21] = posX + width;
	vertices[22] = posY + height; // top = x + width, y + height, z
	vertices[23] = posZ;
	vertices[24] = r;
	vertices[25] = g;
	vertices[26] = b;
	vertices[27] = a;

	// first triangle
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

	// Second triangle
	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;
}

SpriteSquare::~SpriteSquare()
{
	Renderer::GetInstance().DeleteBuffers(VBO, VAO, EBO);
}

float* SpriteSquare::GetVerticesArray()
{
	return vertices;
}

float SpriteSquare::GetX()
{
	return posX;
}

float SpriteSquare::GetY()
{
	return posY;
}

float SpriteSquare::GetZ()
{
	return posZ;
}

float SpriteSquare::GetWidth()
{
	return width;
}

float SpriteSquare::GetHeight()
{
	return height;
}

unsigned int SpriteSquare::GetIndexAmount()
{
	return indicesAmount;
}

void SpriteSquare::BindBuffers()
{
	Renderer::GetInstance().BindBuffers(vertices, verticesAmount, indices, indicesAmount, VBO, VAO, EBO);
}

void SpriteSquare::Draw()
{
	material.UseShader();

	unsigned int transformLoc = glGetUniformLocation(material.GetShader(), "trs");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trs));

	unsigned int projViewLoc = glGetUniformLocation(material.GetShader(), "vp");
	glUniformMatrix4fv(projViewLoc, 1, GL_FALSE, glm::value_ptr(Renderer::GetInstance().GetVPMatrix()));

	Renderer::GetInstance().Draw(indicesAmount, VAO);
}
