/*
Crie uma janela de aplicação com resolução 800x600;
• Aplique uma projeção em perspetiva com um FOV de 45°, e uma relação de especto 800/600;
• Posicione a câmara no ponto (0, 0, 10), direcionada para (0, 0, -1);
• Assuma que o modelo não sofrerá qualquer transformação;
• Defina as coordenadas 3D de um modelo de um cubo de dimensão 2x2x2;
• Cada um dos 24 vértices (6 faces * 4 vértices/face) do cubo deve ser armazenado numa variável glm::vec3;• O conjunto dos 24 vértices deve posteriormente ser armazenado num contentor std::vector;
• Desenhe esse cubo, aplicando as necessárias transformações que o afetam;
• Associe uma função de callback em resposta a movimentos de scroll do rato;
• Faça com que o zoom da câmara (posição no eixo dos z) varie com os movimentos de scroll do rato.
*/

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

#include <iostream>
#include <vector>

#include <Windows.h>
#include <gl\GL.h>

#include <GLFW\glfw3.h>

#include <glm/glm.hpp> // vec3, vec4, ivec4, mat4, ...
#include <glm/gtc/matrix_transform.hpp> // translate, rotate, scale, perspective, ...
#include <glm/gtc/type_ptr.hpp> // value_ptr

void init(void);

#define HEIGHT 800
#define WIDTH 600

using namespace glm;
using namespace std;

GLfloat ZOOM = 10.0f;
GLfloat ANGLE = 0.0f;

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	// Se faz zoom in
	if (yoffset == 1) {
		// Incremento no zoom, varia com a distância da câmara
		ZOOM -= fabs(ZOOM) * 0.1f;
	}
	// Senão, se faz zoom out
	else if (yoffset == -1) {
		// Incremento no zoom, varia com a distância da câmara
		ZOOM += fabs(ZOOM) * 0.1f;
	}
	cout << "ZOOM = " << ZOOM << std::endl;
}

vector<vec3> Load3DModel(void)
{
	// 6 faces * 4 vértices por face
	vec3 point[6 * 4] = {
		// Frente
		vec3(-1.0f, -1.0f,  1.0f),
		vec3(1.0f, -1.0f,  1.0f),
		vec3(1.0f,  1.0f,  1.0f),
		vec3(-1.0f,  1.0f,  1.0f),
		// Trás
		vec3(-1.0f, -1.0f, -1.0f),
		vec3(-1.0f,  1.0f, -1.0f),
		vec3(1.0f,  1.0f, -1.0f),
		vec3(1.0f, -1.0f, -1.0f),
		// Direita
		vec3(1.0f, -1.0f,  1.0f),
		vec3(1.0f, -1.0f, -1.0f),
		vec3(1.0f,  1.0f, -1.0f),
		vec3(1.0f,  1.0f,  1.0f),
		// Esquerda
		vec3(-1.0f, -1.0f,  1.0f),
		vec3(-1.0f,  1.0f,  1.0f),
		vec3(-1.0f,  1.0f, -1.0f),
		vec3(-1.0f, -1.0f, -1.0f),
		// Topo
		vec3(-1.0f,  1.0f,  1.0f),
		vec3(1.0f,  1.0f,  1.0f),
		vec3(1.0f,  1.0f, -1.0f),
		vec3(-1.0f,  1.0f, -1.0f),
		// Baixo
		vec3(-1.0f, -1.0f,  1.0f),
		vec3(-1.0f, -1.0f, -1.0f),
		vec3(1.0f, -1.0f, -1.0f),
		vec3(1.0f, -1.0f,  1.0f)
	};

	vector<vec3> ret;
	for (auto i : point)
		ret.push_back(i);

	return ret;
}


void display(vector<vec3> obj, mat4 mvp)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float* vertex_stream = static_cast<float*>(value_ptr(obj.front()));

	vector<vec3> colors{
		vec3(1.0f, 0.0f, 0.0f), // red
		vec3(0.0f, 1.0f, 0.0f), // green
		vec3(0.0f, 0.0f, 1.0f), // blue
		vec3(1.0f, 1.0f, 0.0f), // yellow
		vec3(1.0f, 0.0f, 1.0f), // magenta
		vec3(0.0f, 1.0f, 1.0f)  // cyan
	};
	// Desenha quad em modo imediato
	glBegin(GL_QUADS);
	/* obj.size() * (obj.front().length()) é o mesmo que (6*4)*3 */
	/* 6 faces * 4 vértices por face * 3 coordenadas por vértice */
	for (int nv = 0; nv < 6 * 4 * 3; nv += 3) {
		//Uma Cor por face
		glColor3f(colors[nv / (4 * 3)].r, colors[nv / (4 * 3)].g, colors[nv / (4 * 3)].b);
		vec4 vertex = vec4(vertex_stream[nv], vertex_stream[nv + 1], vertex_stream[nv + 2], 1.0f);
		//calculo das cordenadas de recorte
		vec4 transformed_vertex = mvp * vertex;
		//divisao da prespetiva
		vec4 normalized_vertex = transformed_vertex / transformed_vertex.w;

		// Silly Vertex warping idk
		//normalized_vertex.x = trunc(normalized_vertex.x * 100) / 100;
		//normalized_vertex.y = trunc(normalized_vertex.y * 100) / 100;
		
		//desenha o vertice
		glVertex3f(normalized_vertex.x, normalized_vertex.y, normalized_vertex.z);
	}
	glEnd();
}

int main(void) 
{
	vector<vec3> obj = Load3DModel();

	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(HEIGHT, WIDTH, "Silly Cube", NULL, NULL);

	glfwMakeContextCurrent(window);

	init();
	
	glfwSetScrollCallback(window, scrollCallback);

	//projection
	mat4 projection = perspective(radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	//view orthodontal
	//mat4 projection = ortho(-2.0f, 2.0f, -2.0f, 2.0f, 0.0f, 20.0f);

	while (!glfwWindowShouldClose(window))
	{
		//view
		mat4 view = lookAt(
			vec3(0.0f, 0.0f, ZOOM),		// Posição da câmara no mundo
			vec3(0.0f, 0.0f, -1.0f),	// Direção para a qual a câmara esta apontada
			vec3(0.0f, 1.0f, 0.0f)		// Vector vertical
		);
		//model
		mat4 model = mat4(1.0f);
		//model rotation
		model = rotate(model, ANGLE -= 0.03f, normalize(vec3(1.0f, -1.0f, 1.0f)));
		//MVP
		mat4 mvp = projection * view * model;

		display(obj, mvp);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}


void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	// Descomentar para ativar o Face Culling
	//glEnable(GL_CULL_FACE);
}
