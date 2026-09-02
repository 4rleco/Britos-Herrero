#include "Shape.h"

#include "EngineAPI.h"

class ENGINE_API Triangle : public Shape
{
private:
	float vertices[9];
	unsigned int indices[3];

public:
	Triangle();
	Triangle(float posX, float posY, float posZ, float width, float height);
	~Triangle();

	float* GetVerticesArray();

	float GetX() override;
	float GetY() override;
	float GetZ() override;

	float GetWidth() override;
	float GetHeight() override;

	unsigned int GetIndexAmount();

	void BindBuffers();

	void Draw() override;
};