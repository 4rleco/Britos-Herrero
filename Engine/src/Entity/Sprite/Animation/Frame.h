#pragma once

struct UVCoords
{
	float u;
	float v;
};

class Frame
{
public:
	UVCoords uvCoords[4];

	Frame();
	~Frame();
};