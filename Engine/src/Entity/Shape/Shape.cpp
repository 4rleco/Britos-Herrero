#include "Shape.h"

Shape::Shape(float posX, float posY, float posZ, float width, float height) :
	Entity2D(posX, posY, posZ, width, height)
{

}

Shape::Shape(float posX, float posY, float posZ, float width, float height,
	float r, float g, float b, float a) :Entity2D(posX, posY, posZ, width, height, r, g, b, a)
{

}

Shape::~Shape()
{

}

float Shape::GetX()
{
	return posX;
}

float Shape::GetY()
{
	return 0.0f;
}

float Shape::GetZ()
{
	return 0.0f;
}

float Shape::GetWidth()
{
	return 0.0f;
}

float Shape::GetHeight()
{
	return 0.0f;
}
