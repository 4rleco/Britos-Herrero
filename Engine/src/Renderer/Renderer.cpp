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

void Renderer::BindBuffers()
{
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void Renderer::Draw(float* vertices)
{
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * 9, vertices, GL_STATIC_DRAW);
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
	glDeleteBuffers(1, &VBO);

	// Cleans all the resources of the window and destroys it
	glfwDestroyWindow(window);

	// Close the GLFW functions
	glfwTerminate();
}