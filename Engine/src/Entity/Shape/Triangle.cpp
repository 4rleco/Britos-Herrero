#include "Triangle.h"

Triangle::Triangle() :
	Shape(posX, posY, posZ, width, height)
{

}

Triangle::Triangle(float posX, float posY, float posZ, float width, float height) :
	Shape(posX, posY, posZ, width, height)
{
	material.SetFilepath("Shape.shader");
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

	// top
	vertices[14] = posX;
	vertices[15] = posY + height; // top = x, y + height, z
	vertices[16] = posZ;
	vertices[17] = 1.0f;
	vertices[18] = 1.0f;
	vertices[19] = 1.0f;
	vertices[20] = 1.0f;

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
}

Triangle::Triangle(float posX, float posY, float posZ, float width, float height,
	float r, float g, float b, float a) : Shape(posX, posY, posZ, width, height, r, g, b, a)
{
	material.SetFilepath("Shape.shader");
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

	// top
	vertices[14] = posX;
	vertices[15] = posY + height; // top = x, y + height, z
	vertices[16] = posZ;
	vertices[17] = r;
	vertices[18] = g;
	vertices[19] = b;
	vertices[20] = a;

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
}

Triangle::~Triangle()
{
	Renderer::GetInstance().DeleteBuffers(VBO, VAO, EBO);
}

float* Triangle::GetVerticesArray()
{
	return vertices;
}

float Triangle::GetX()
{
	return posX;
}

float Triangle::GetY()
{
	return posY;
}

float Triangle::GetZ()
{
	return posZ;
}

float Triangle::GetWidth()
{
	return width;
}

float Triangle::GetHeight()
{
	return height;
}

unsigned int Triangle::GetIndexAmount()
{
	return 0;
}

void Triangle::BindBuffers()
{
	Renderer::GetInstance().BindBuffers(vertices, verticesAmount, indices, indicesAmount, VBO, VAO, EBO);
}

void Triangle::Draw()
{
	material.UseShader();
	Renderer::GetInstance().Draw(indicesAmount, VAO);
}
