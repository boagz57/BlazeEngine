#include "Precompiled.h"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Graphics.h"


Graphics::Graphics(Entity* obj) : obj(obj)
{
}

void Graphics::Draw()
{
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}

void Graphics::InitializeBuffers()
{
	MyOpenGL::InitializeGLBuffers(obj->objVerts);
}
