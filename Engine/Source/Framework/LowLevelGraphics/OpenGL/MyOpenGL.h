#pragma once
#include "Macro.h"
#include "UniversalTypeDefs.h"
#include "GL/glew.h"
#include "Math/Vertex3D/Vertex3D.h"
#include "Vector/Vector.h"
#include <iostream>
#include <fstream>

namespace MyOpenGL
{
	void InitializeGLBuffers(BlazeFramework::Vector<BlazeFramework::Math::Vertex3D> objVerts);
	void MoveTriangle(float x, float y);
	std::string ReadShaderCode(const char8* fileName, const char8* typeOfShader);
	void InstallShaders();
}
