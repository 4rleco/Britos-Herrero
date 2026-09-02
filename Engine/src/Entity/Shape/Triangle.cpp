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

	// bottom right
	vertices[3] = posX + width;
	vertices[4] = posY - height; // bottom right = x + widht, y -height, z
	vertices[5] = posZ;

	// top
	vertices[6] = posX;
	vertices[7] = posY + height; // top = x, y + height, z
	vertices[8] = posZ;

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
}

Triangle::~Triangle()
{

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
	Renderer::GetInstance().BindBuffers(vertices,  indices, 3, VBO, VAO, EBO);
}

void Triangle::Draw()
{
	material.UseShader();
	Renderer::GetInstance().Draw(indices, 3, VAO);
}
