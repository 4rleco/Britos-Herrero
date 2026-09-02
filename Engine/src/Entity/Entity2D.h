#include "Entity.h"
#include "Material/Material.h"

class Entity2D : public Entity
{
protected:
	Material material;

public:
	Entity2D(float posX, float posY, float posZ, float width, float height);
	~Entity2D();

	void SetMaterial();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;

	void Draw() override;
};