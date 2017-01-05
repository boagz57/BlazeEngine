#include "Precompiled.h"
#include "LowLevelGraphics/OpenGL/MyOpenGL.h"
#include "Graphics.h"


Graphics::Graphics(Entity* obj) : obj(obj)
{
}

void Graphics::Draw()
{
}

void Graphics::InitializeBuffers()
{
	MyOpenGL::InitializeGLBuffers(obj->objVerts);
}
