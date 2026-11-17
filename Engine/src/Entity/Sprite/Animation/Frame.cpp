#include "Frame.h"

Frame::Frame()
{
	uvCoords[0].u = 0.0f;
	uvCoords[0].v = 0.0f;

	uvCoords[1].u = 1.0f;
	uvCoords[1].v = 0.0f;

	uvCoords[2].u = 0.0f;
	uvCoords[2].v = 1.0f;

	uvCoords[3].u = 1.0f;
	uvCoords[3].v = 1.0f;
}

Frame::~Frame()
{

}
