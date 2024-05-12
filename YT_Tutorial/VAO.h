#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "VBO.h"

class VAO
{
public:
	GLuint ID;
	VAO();
	void LinkVBO(VBO VBO, GLuint layout);
	void Bind();
	void Unbind();
	void Delete();
};


#endif // !VBO_CLASS_H
