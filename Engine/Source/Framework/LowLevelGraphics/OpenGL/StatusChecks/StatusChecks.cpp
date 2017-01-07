#include "Precompiled.h"
#include "Universal/Macro.h"
#include "StatusChecks.h"

namespace BlazeFramework
{
	namespace OpenGL
	{
		bool CheckGLShaderStatus(GLuint shaderID)
		{
			GLint compileStatus;
			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
			if (compileStatus != GL_TRUE)
			{
				GLint infoLogLength;
				glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
				GLchar* buffer = new GLchar[infoLogLength];

				GLsizei bufferSize;
				glGetShaderInfoLog(shaderID, infoLogLength, &bufferSize, buffer);

				LOG(buffer);

				delete[] buffer;
				return false;
			}

			return true;
		}

		bool CheckGLProgramStatus(GLuint programID)
		{
			GLint linkStatus;
			glGetProgramiv(programID, GL_LINK_STATUS, &linkStatus);
			if (linkStatus != GL_TRUE)
			{
				GLint infoLogLength;
				glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
				GLchar* buffer = new GLchar[infoLogLength];

				GLsizei bufferSize;
				glGetProgramInfoLog(programID, infoLogLength, &bufferSize, buffer);

				LOG(buffer);

				delete[] buffer;
				return false;
			}

			return true;
		}
	}
}