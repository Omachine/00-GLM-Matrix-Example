#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

#include <iostream>

#include <Windows.h>
#include <gl\GL.h>

#include <GLFW\glfw3.h>

void init(void);
void display(void);

#define WIDTH 800
#define HEIGHT 600

int main(void) {
	GLFWwindow* window;

	if (!glfwInit()) return -1;

	window = glfwCreateWindow(WIDTH, HEIGHT, "GLSL - Triangulo - Modo Imediato", NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	init();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		display();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void init(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// Desenha tri?ngulo em modo imediato
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.90f, -0.90f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.85f, -0.90f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.90f, 0.85f);
	glEnd();
}