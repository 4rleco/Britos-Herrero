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

	/* Cleans all the resources left by the window (Use it when the program ends) */
	void CleanResources();

	/* Cleans the actual frame (Goes at the start of the drawing) */
	void Clear();

	/* Switchs the buffers and configurates the next frame (Needed for the correct working of the program) */
	void Update();

	/* Checks if the window has to be closed */
	bool ShouldClose();

	/* Returns width */
	int GetWidth() const;

	/* Returns height */
	int GetHeight() const;
};