#pragma once
#include "Macro.h"
#include "UniversalTypeDefs.h"
#include "GL/glew.h"
#include <iostream>
#include <fstream>

namespace MyOpenGL
{
	void InitializeGLBuffers();
	void MoveTriangle(float x, float y);
	std::string ReadShaderCode(const char8* fileName, const char8* typeOfShader);
	void InstallShaders();
}
