#pragma once

#include <GL/glew.h>

#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(int x, int y, int rotation);
	~Triangle();
	
	void Draw() override;

private:
	

};

