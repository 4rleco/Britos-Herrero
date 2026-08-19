#pragma once

#include <GLFW/glfw3.h>

#include "EngineAPI.h"

ENGINE_API class Window
{

private:
	GLFWwindow* window;

	int windowWidth = 0;
	int windowHeight = 0;

public:
	/* Builts the structure of the window */
	void set(int width, int height, const char* title);
	/* Close the window */
	void close();
	/* Cleans all the resources left by the window (Use it when the program ends) */
	void cleanResources();

	/* Cleans the actual frame (Goes at the start of the drawing) */
	void clear();
	/* Switchs the buffers and configurates the next frame (Needed for the correct working of the program) */
	void update();

	/* Checks if the window has to be closed */
	bool shouldClose();

	/* Returns width */
	int getWidth() const;
	/* Returns height */
	int getHeight() const;
};