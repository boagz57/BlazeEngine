#pragma once
#include "Universal/Macro.h"
#include "Universal/UniversalTypeDefs.h"
#include "GL/glew.h"
#include "Math/Vector2D.h"
#include "Universal/UniversalTypeDefs.h"
#include "DataStructures/Vector/Vector.h"
#include <iostream>
#include <fstream>

namespace MyOpenGL
{
	void InitializeBuffers();
	std::string ReadShaderCode(const char8* cFileName, const char8* cTypeOfShader);
	void InstallShaders();
	void sendUniformMat4Data(const char8* whatShaderVariableToSendTo, GLfloat* matrixData);
	void Draw();
}
