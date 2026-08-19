#pragma once

#include <GLFW/glfw3.h>

#include "EngineAPI.h"

ENGINE_API class Window
{
public:
	/* Builts the structure of the window */
	void set(int width, int height, const char* title);
	/* Close the window */
	void close();

	/* Cleans the actual frame (Goes at the start of the drawing) */
	void clean();

	/* Checks if the window has to be closed */
	bool shouldClose();

	bool getStatus() const;

	/* Returns width */
	int getWidth() const;
	/* Returns height */
	int getHeight() const;
	/* Returns window */
	GLFWwindow* getWindow() const;

private:
	GLFWwindow* window = nullptr;

	int windowWidth = 0;
	int windowHeight = 0;

	bool hasStarted = false;

};