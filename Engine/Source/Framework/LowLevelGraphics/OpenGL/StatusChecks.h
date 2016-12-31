#pragma once
#include "GL/glew.h"

namespace BlazeFramework
{
	namespace OpenGL
	{
		bool CheckGLShaderStatus(GLuint shaderID);
		bool CheckGLProgramStatus(GLuint programID);
	}
}