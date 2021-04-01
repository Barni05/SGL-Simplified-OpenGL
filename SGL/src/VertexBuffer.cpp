#include "VertexBuffer.h"
#include "Headers.h"
VertexBuffer::VertexBuffer(unsigned int size, const void* data):Buffer(size, data)
{
	GLCall(glGenBuffers(1, &mRendererID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, mRendererID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	std::cout << "Size: " << size << std::endl;
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &mRendererID));
}

void VertexBuffer::SetData(unsigned int size, const void* data)
{
	Bind();
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

void VertexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, mRendererID));
}

void VertexBuffer::Unbind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}