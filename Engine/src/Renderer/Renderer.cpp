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

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	std::cout << "GLEW OK" << std::endl;
}

void Renderer::SetWindowContext(GLFWwindow* window)
{
	glfwMakeContextCurrent(window);
}

void Renderer::BindBuffers(float* vertices, const int verticiesAmount, unsigned int* indices, unsigned int indexAmount,
	unsigned int& VBO, unsigned int& VAO, unsigned int& EBO)
{
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticiesAmount, vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indexAmount, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);	
}

void Renderer::BindTexure(float* vertices, const int verticiesAmount, unsigned int* indices, unsigned int indexAmount,
	unsigned int& VBO, unsigned int& VAO, unsigned int& EBO,
	unsigned int& texture, unsigned char* data, const char* filepath, int& width, int& height, int& nrChannels)
{
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticiesAmount, vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indexAmount, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void*)(sizeof(float) * 7));
	glEnableVertexAttribArray(2);

	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);

	// load image, create texture and generate mipmaps
	// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	data = stbi_load(filepath, &width, &height, &nrChannels, 4);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		std::cout << "Texture loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

void Renderer::SetVPMatrix(float width, float height)
{
	proj = glm::ortho(0.0f, width, 0.0f, height, -100.0f, 100.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));
}

glm::mat4 Renderer::GetVPMatrix()
{
	glm::mat4 vp = proj * view;
	return vp;
}

void Renderer::Draw(int indexAmount, unsigned int& VAO)
{
	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, indexAmount, GL_UNSIGNED_INT, 0);
}

void Renderer::DrawSprite(int indexAmount, unsigned int& VAO, unsigned int texture)
{
	glBindTexture(GL_TEXTURE_2D, texture);

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

void Renderer::DeleteTexBuffer(unsigned int& texture)
{
	glDeleteTextures(1, &texture);
}

/* Cleans all the leftover resources left by the window and the window itself */
void Renderer::CleanData(GLFWwindow* window)
{
	// Cleans all the resources of the window and destroys it
	glfwDestroyWindow(window);

	// Close the GLFW functions
	glfwTerminate();
}