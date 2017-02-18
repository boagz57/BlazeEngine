#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Universal/UniversalTypeDefs.h"
#include <fstream>
#include "GL/glew.h"
#include "MyOpenGL.h"
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D.h"
#include "Universal/Globals.h"
#include "StatusChecks/StatusChecks.h"


namespace MyOpenGL
{
	using namespace BlazeFramework;
	using namespace Math;

	std::string ReadShaderCode(const char8* cShaderFilePath, const char8* cTypeOfShader)
	{
		std::ifstream shaderFileInputStream(cShaderFilePath);
		if (!shaderFileInputStream.good())
		{
			LOG("%s Shader File failed to load!\n", cTypeOfShader);
		};

		return std::string(std::istreambuf_iterator<char8>(shaderFileInputStream), std::istreambuf_iterator<char8>());
	}

	void InstallShaders()
	{
		//Create GL Shaders
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		//Add source or text file to shader object
		std::string temp = ReadShaderCode("../Engine/Source/Framework/LowLevelGraphics/OpenGL/Shaders/VertexShader.glsl", "Vertex").c_str();
		const GLchar* cAdapter[1];

		cAdapter[0] = temp.c_str();
		glShaderSource(vertexShaderID, 1, cAdapter, 0);
		temp = ReadShaderCode("../Engine/Source/Framework/LowLevelGraphics/OpenGL/Shaders/FragmentShader.glsl", "Fragment").c_str();
		cAdapter[0] = temp.c_str();
		glShaderSource(FragmentShaderID, 1, cAdapter, 0);

		glCompileShader(vertexShaderID);
		glCompileShader(FragmentShaderID);

		if (!BlazeFramework::OpenGL::CheckGLShaderStatus(vertexShaderID) || !BlazeFramework::OpenGL::CheckGLShaderStatus(FragmentShaderID))
			return;

		//Create GL Program
		GLuint programID = glCreateProgram();
		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, FragmentShaderID);

		glLinkProgram(programID);

		if (!BlazeFramework::OpenGL::CheckGLProgramStatus(programID))
		{
			LOG("Failed to link openGL program");
			return;
		}

		glUseProgram(programID);
	}
}
