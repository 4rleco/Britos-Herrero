#include "Renderer.h"

Renderer& Renderer::GetInstance()
{
	static Renderer instance;
	return instance;
}

void Renderer::CheckGlewStatus()
{
	 GLenum err = glewInit();

    std::cout << "GLEW result: " << err << std::endl;

    if (err != GLEW_OK)
    {
        std::cout << "GLEW Error: "
                  << reinterpret_cast<const char*>(glewGetErrorString(err))
                  << std::endl;
        return;
    }

    std::cout << "GLEW OK" << std::endl;
}

void Renderer::SetWindowContext(GLFWwindow* window)
{
	glfwMakeContextCurrent(window);
}

void Renderer::BindBuffers(float* vertices)
{
	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, vertices, GL_STATIC_DRAW);
}

void Renderer::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

/* Switchs the buffers and configurates the next frame (Needed for the correct working of the program) */
void Renderer::UpdateBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);

	glfwPollEvents();
}

void Renderer::CleanWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

/* Cleans all the leftover resources left by the window and the window itself */
void Renderer::CleanData(GLFWwindow* window)
{
	// Cleans all the resources of the window and destroys it
	glfwDestroyWindow(window);

	// Close the GLFW functions
	glfwTerminate();
}