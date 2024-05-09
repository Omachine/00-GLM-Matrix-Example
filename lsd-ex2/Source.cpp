/*Crie agora uma aplicação com resolução 1280x720 e que exiba alternadamente na janela as cores azul
e vermelho.
Teste o funcionamento com single buffer e double buffer.
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


int main(void) 
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_FALSE);
	window = glfwCreateWindow(1280, 720, "Exercicio 2 P3D", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	bool color = 0;

	while (!glfwWindowShouldClose(window))
	{
		if (color)
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // blue
		else
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // red
		color = !color;

		glClear(GL_COLOR_BUFFER_BIT);

	

		// Add a delay to allow the color change to be visible
		glfwWaitEventsTimeout(1.0); // delay for 1 second

		//glfwSwapBuffers(window);
		glFinish();
		glfwPollEvents();

	}
	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}
