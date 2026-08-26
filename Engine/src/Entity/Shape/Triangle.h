#include "Shape.h"

class Triangle : public Shape
{
private:
	float vertices[9];

public:
	Triangle(float posX, float posY, float posZ, float width, float height);
	~Triangle();

	float* GetVerticesArray();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;

	void Draw() override;
};