#include "SpriteSquare.h"

SpriteSquare::SpriteSquare() :
	Sprite(filepath, posX, posY, posZ, width, height)
{

}

SpriteSquare::SpriteSquare(std::string filepath, float posX, float posY, float posZ, float width, float height) :
	Sprite(filepath, posX, posY, posZ, width, height)
{
	material.SetFilepath("Sprtie.shader");
	SetMaterial();
	material.SetShader();

	textureImporter = TextureImporter(filepath);

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

	// top left
	vertices[18] = posX - width;
	vertices[19] = posY + height; // top right = x - width, y + height, z
	vertices[20] = posZ;
	// r g b a
	vertices[21] = 1.0f;
	vertices[22] = 1.0f;
	vertices[23] = 1.0f;
	vertices[24] = 1.0f;
	// u v
	vertices[25] = 0.0f;
	vertices[26] = 1.0f;

	// top right
	vertices[27] = posX + width;
	vertices[28] = posY + height; // top = x + width, y + height, z
	vertices[29] = posZ;
	// r g b a
	vertices[30] = 1.0f;
	vertices[31] = 1.0f;
	vertices[32] = 1.0f;
	vertices[33] = 1.0f;
	// u v
	vertices[34] = 1.0f;
	vertices[35] = 1.0f;

	// first triangle
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 3;

	// Second triangle
	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;
}

SpriteSquare::SpriteSquare(std::string filepath, float posX, float posY, float posZ, float width, float height,
	float r, float g, float b, float a) : Sprite(filepath, posX, posY, posZ, width, height, r, g, b, a)
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
	vertices[16] = 1.0f;
	vertices[17] = 0.0f;

	// top left
	vertices[18] = posX - width;
	vertices[19] = posY + height; // top right = x - width, y + height, z
	vertices[20] = posZ;
	// r g b a
	vertices[21] = r;
	vertices[22] = g;
	vertices[23] = b;
	vertices[24] = a;
	// u v
	vertices[25] = 0.0f;
	vertices[26] = 1.0f;

	// top right
	vertices[27] = posX + width;
	vertices[28] = posY + height; // top = x + width, y + height, z
	vertices[29] = posZ;
	// r g b a
	vertices[30] = r;
	vertices[31] = g;
	vertices[32] = b;
	vertices[33] = a;
	// u v
	vertices[34] = 1.0f;
	vertices[35] = 1.0f;

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

void SpriteSquare::BindTexture()
{
	Renderer::GetInstance().BindTexure(vertices, verticesAmount, indices, indicesAmount, VBO, VAO, EBO,
		filepath, texture,	textureImporter.GetWidth(), textureImporter.GetHeight(), textureImporter.GetNrChannels());
}

void SpriteSquare::Draw()
{
	material.UseShader();

	unsigned int transformLoc = glGetUniformLocation(material.GetShader(), "trs");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trs));

	unsigned int projViewLoc = glGetUniformLocation(material.GetShader(), "vp");
	glUniformMatrix4fv(projViewLoc, 1, GL_FALSE, glm::value_ptr(Renderer::GetInstance().GetVPMatrix()));

	Renderer::GetInstance().DrawSprite(indicesAmount, VAO, texture);
}