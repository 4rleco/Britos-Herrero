#include "Shape.h"

#include "EngineAPI.h"

class ENGINE_API Triangle : public Shape
{
private:
	static const int verticesAmount = 21;
	float vertices[verticesAmount];

	static const int indicesAmount = 3;
	unsigned int indices[indicesAmount];

public:
	Triangle();
	//sin color
	Triangle(float posX, float posY, float posZ, float width, float height);
	// todos los vértices usan el mismo color y transparencia
	Triangle(float posX, float posY, float posZ, float width, float height,
		float r, float g, float b, float a);
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