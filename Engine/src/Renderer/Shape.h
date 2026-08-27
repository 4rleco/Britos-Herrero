#pragma once

#include "Entity.h"

class Shape : public Entity
{
public:
	virtual void Draw() = 0;

protected:
	void setVertexCount(int vertexCount);
	void setVertexes();

	void cleanVertexes();

	int getVertexCount() const;
	float* getVertexes() const;

private:
	int vertexCount;

	float* vertexes;
};

