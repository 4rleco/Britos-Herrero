#include "Shape.h"

void Shape::setVertexCount(int vertexCount)
{
	this->vertexCount = vertexCount;
}

void Shape::setVertexes()
{
	if (vertexes == nullptr)
	{
		vertexes = new float[vertexCount];

		switch (vertexCount / 2)
		{
		case 3:

			for (int i = 0; i < vertexCount; i++)
			{
				switch (i)
				{
				case 0:

					vertexes[i] = getPosX() - 0.5;

					break;
				case 1:

					vertexes[i] = getPosY() - 0.5;

					break;
				case 2:

					vertexes[i] = getPosX();

					break;
				case 3:

					vertexes[i] = getPosY() + 0.5;

					break;
				case 4:

					vertexes[i] = getPosX() + 0.5;

					break;
				case 5:

					vertexes[i] = getPosY();

					break;
				default:
					break;
				}
			}

			break;
		case 4:



			break;
		default:
			break;
		}
	}
}

void Shape::cleanVertexes()
{
	if (vertexes != nullptr)
		delete[] vertexes;
}

int Shape::getVertexCount() const
{
	return vertexCount;
}

float* Shape::getVertexes() const
{
	return vertexes;
}