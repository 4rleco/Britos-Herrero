#include "../Entity2D.h"

class Shape : public Entity2D
{
private:

public:
	Shape(float posX, float posY, float posZ, float width, float height);
	Shape(float posX, float posY, float posZ, float width, float height,
		float r, float g, float b, float a);
	~Shape();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;
};