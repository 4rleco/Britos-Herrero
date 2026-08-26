#pragma once

#include <GLFW/glfw3.h>

#include "EngineAPI.h"

class Window
{
private:
	GLFWwindow* window;

	int windowWidth;
	int windowHeight;

public:
	Window();

	~Window();

	/* Builts the structure of the window */
	void InitWindow(int width, int height, const char* title);

	/* Close the window */
	void Close();

	/* Cleans the actual frame (Goes at the start of the drawing) */
	void Clear();

	/* Checks if the window has to be closed */
	bool ShouldClose();

	/* Returns width */
	int GetWidth() const;

	/* Returns height */
	int GetHeight() const;

	/*Returns glfw window*/
	GLFWwindow* GetWindow() const;
};