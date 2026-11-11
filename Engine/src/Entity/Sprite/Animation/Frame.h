#pragma once

struct UVCoords 
{
	float u, v;
};

class Frame
{
public:
	UVCoords uvCoords[4];

	Frame();
	~Frame();	
};