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

void Renderer::BindBuffers(float* vertices, unsigned int* indices, unsigned int indexAmount, 
	unsigned int& VBO, unsigned int& VAO, unsigned int& EBO)
{
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	glEnableVertexAttribArray(0);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indexAmount, indices, GL_STATIC_DRAW);
}

void Renderer::Draw(unsigned int* indices, unsigned int indexAmount, unsigned int& VAO)
{
	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, indexAmount, GL_UNSIGNED_INT, 0);
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

void Renderer::DeleteBuffers(unsigned int& VBO, unsigned int& VAO, unsigned int& EBO)
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &EBO);
}

/* Cleans all the leftover resources left by the window and the window itself */
void Renderer::CleanData(GLFWwindow* window)
{
	// Cleans all the resources of the window and destroys it
	glfwDestroyWindow(window);

	// Close the GLFW functions
	glfwTerminate();
}