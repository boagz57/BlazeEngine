#pragma once
#include "GL/glew.h"

/*This code is checking to make sure openGL's shader's and program's are loaded 
without issue. These functions will return information if there are problems.*/

namespace BlazeFramework
{
	namespace OpenGL
	{
		bool CheckGLShaderStatus(GLuint shaderID);
		bool CheckGLProgramStatus(GLuint programID);
	}
}