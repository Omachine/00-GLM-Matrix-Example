/*Crie uma aplicação com resolução 800x600; double buffer; que implemente um callback de resposta a
erros, apresentando na consola a respetiva descrição; e que exiba na janela a cor azul.
*/
// Define GLEW_STATIC to link the static version of GLEW
#define GLEW_STATIC
// Include the GLEW, GLFW, and iostream libraries
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

// Link the GLEW, GLFW, and OpenGL libraries
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

#include <windows.h>

// Enable the NVIDIA high-performance graphics if available
extern "C" {
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

// Define a callback function to handle GLFW errors
void ErrorVCallbackFunction(int error, const char* description)
{
	printf("%s\n", description);
}

int main(void)
{
	// Set the error callback function for GLFW
	glfwSetErrorCallback(ErrorVCallbackFunction);

	// Declare a pointer to a GLFWwindow object
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	// Create a GLFW window with a size of 800x600 and title "Exercicio 1 P3D"
	window = glfwCreateWindow(800, 600, "Exercicio 1 P3D", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the context of the specified window current for the calling thread
	glfwMakeContextCurrent(window);
	
	// Set the clear color to blue
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);


	while (!glfwWindowShouldClose(window))
	{
		// Clear the color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap the front and back buffers of the specified window
		glfwSwapBuffers(window);

		// Process all pending events
		glfwPollEvents();
	}
	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}
