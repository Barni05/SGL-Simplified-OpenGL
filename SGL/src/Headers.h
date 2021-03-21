#pragma once
#include <GL/glew.h>
#include <iostream>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Buffer.h"


#define ASSERT(x) if(x==0) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLCheckError)


void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

void GLCheckError()
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ") " << std::endl;
	}
}