#include "Triangle.h"

#include "Renderer.h"

Triangle::Triangle(int x, int y, int rotation)
{
	setPosX(x);
	setPosY(y);
	setRotation(rotation);

	setVertexes();
}

Triangle::~Triangle()
{
	cleanVertexes();
}

void Triangle::Draw()
{
	Renderer::GetInstance().BindBuffers(getVertexCount(), getVertexes());

	glDrawArrays(GL_TRIANGLES, 0, 3);
}
