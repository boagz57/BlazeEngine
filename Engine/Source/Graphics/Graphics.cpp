#include "Precompiled.h"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Graphics.h"


Graphics::Graphics()
{
}

void Graphics::Draw()
{
}

void Graphics::InitializeBuffers()
{
	glGenBuffers(1, &vertexBufferID);
	glGenBuffers(1, &indexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);

	glBufferData(GL_ARRAY_BUFFER, cMaxBufferSize, nullptr, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cMaxBufferSize, nullptr, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, nullptr);
}

void Graphics::Update(Entity& obj)
{
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(BlazeFramework::Math::Vertex3D) * 3, &triangle.front());
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLushort) * 3, &indicies.front());
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}
