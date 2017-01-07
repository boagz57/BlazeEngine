#pragma once
#include "Universal/Macro.h"
#include "Universal/UniversalTypeDefs.h"
#include "GL/glew.h"
#include "Math/Vertex3D/Vertex3D.h"
#include "Universal/UniversalTypeDefs.h"
#include "DataStructures/Vector/Vector.h"
#include <iostream>
#include <fstream>

namespace MyOpenGL
{
	void InitializeGLBuffers(BlazeFramework::Vector<BlazeFramework::Math::Vertex3D> objVerts);
	void MoveTriangle(sfloat x, sfloat y);
	std::string ReadShaderCode(const char8* fileName, const char8* typeOfShader);
	void InstallShaders();
}
