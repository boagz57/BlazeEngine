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
	MyOpenGL::InitializeGLBuffers(triangle);
}

void Graphics::Update(Entity& obj)
{
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}
