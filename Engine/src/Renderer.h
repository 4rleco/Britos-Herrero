#pragma once

#include <GLFW/glfw3.h>

#include "EngineAPI.h"

ENGINE_API class Renderer
{
public:
	void setWindowContext(GLFWwindow* window);
	
	/* Switchs the buffers and configurates the next frame (Needed for the correct working of the program) */
	void updateBuffers(GLFWwindow* window);
	
	void drawTriangle(float x, float y, float size);

	void cleanWindow();
	/* Cleans all the resources left by the window (Use it when the program ends) */
	void cleanData(GLFWwindow* window);

private:

};