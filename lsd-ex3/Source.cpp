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
// Global variables for the color
float r = 0.0f, g = 0.0f, b = 1.0f; // Initialize to blue

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
        case GLFW_KEY_R:
            r = 1.0f; g = 0.0f; b = 0.0f; // Red
            break;
        case GLFW_KEY_G:
            r = 0.0f; g = 1.0f; b = 0.0f; // Green
            break;
        case GLFW_KEY_B:
            r = 0.0f; g = 0.0f; b = 1.0f; // Blue
            break;
        case GLFW_KEY_1:
            if (mods == GLFW_MOD_ALT) {
                // Coloca a janela em modo de full screen
                GLFWmonitor* monitor = glfwGetPrimaryMonitor();
                const GLFWvidmode* mode = glfwGetVideoMode(monitor);
                glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
            }
            break;
        case GLFW_KEY_2:
            if (mods == GLFW_MOD_ALT) {
                // Coloca a janela em modo normal
                glfwSetWindowMonitor(window, NULL, 100, 100, 800, 600, 0);
            }
            break;
        }
    }
}

// Função de callback para eventos de mouse
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        // Encerra a aplicação
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
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
        window = glfwCreateWindow(800, 600, "Exercicio 3 P3D", nullptr, nullptr);

        if (!window)
        {
            glfwTerminate();
            return -1;
        }

    // Define as funções de callback
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(r, g, b, 1.0f); // Set the clear color
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

        glfwSwapBuffers(window); // Swap buffers to make the color change visible

        glfwPollEvents(); // Process all pending events
    }
    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}