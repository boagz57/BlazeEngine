#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Universal/UniversalTypeDefs.h"
#include <fstream>
#include "GL/glew.h"
#include "MyOpenGL.h"
#include "DataStructures/Vector/Vector.h"
#include "Math/Vertex3D/Vertex3D.h"
#include "Universal/Globals.h"
#include "StatusChecks/StatusChecks.h"


namespace MyOpenGL
{
	using namespace BlazeFramework;
	using namespace Math;

	void InitializeGLBuffers(Vector<Vertex3D> objVerts)
	{
		GLuint bufferID;
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glBufferData(GL_ARRAY_BUFFER, objVerts.size() * sizeof(Vertex3D), &objVerts.front(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (sizeof(GLfloat)) * 3, nullptr);

		GLushort indices[] =
		{
			0,1,2
		};

		GLuint indexBufferID;
		glGenBuffers(1, &indexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}

	void MoveTriangle(sfloat x, sfloat y)
	{
		/*Vertex3D velocity(x, y, 0.0f);

		for (int i = 0; i < 3; i++)
		{
			triangle.at(i) = triangle.at(i) + velocity * engineClock.TimeSinceLastFrame();
		};

		glBufferSubData(GL_ARRAY_BUFFER, 0, triangle.size() * sizeof(Vertex3D), &triangle.front());*/
	}

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

		//Compile GL Shader
		glCompileShader(vertexShaderID);
		glCompileShader(FragmentShaderID);

		if (!BlazeFramework::OpenGL::CheckGLShaderStatus(vertexShaderID) || !BlazeFramework::OpenGL::CheckGLShaderStatus(FragmentShaderID))
			return;

		//Create GL Program
		GLuint programID = glCreateProgram();
		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, FragmentShaderID);

		//Link GL Program
		glLinkProgram(programID);

		if (!BlazeFramework::OpenGL::CheckGLProgramStatus(programID))
		{
			LOG("Failed to link openGL program");
			return;
		}

		//Use program
		glUseProgram(programID);
	}
}
