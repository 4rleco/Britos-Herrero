#include "Entity.h"

class Entity2D : public Entity
{
private:


public:
	Entity2D(float posX, float posY, float posZ, float width, float height);
	~Entity2D();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;

	void Draw() override;
};