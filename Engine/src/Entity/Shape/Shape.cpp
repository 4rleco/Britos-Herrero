#include "Shape.h"

Shape::Shape(float posX, float posY, float posZ, float width, float height) :
	Entity2D(posX, posY, posZ, width, height)
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
