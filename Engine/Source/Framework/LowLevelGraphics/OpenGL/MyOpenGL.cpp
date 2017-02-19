#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Universal/UniversalTypeDefs.h"
#include <fstream>
#include "GL/glew.h"
#include "ShapeData.h"
#include "MyOpenGL.h"
#include "DataStructures/Vector/Vector.h"
#include "Math/Vector2D.h"
#include "Universal/Globals.h"
#include "StatusChecks/StatusChecks.h"

static GLuint TriangleVertexBufferID;
static GLuint TriangleIndexBufferID;

//The max buffer size in bytes I want to send down initially to GPU
static uint16 const c_MaxBufferSize = 1024;

GLuint programID;

namespace MyOpenGL
{
	using namespace BlazeFramework;

	void InitializeBuffers()
	{
		using namespace BlazeGraphics;
		using namespace BlazeFramework;

		transformedVerts.resize(c_numTransformedVertices);

		glGenBuffers(1, &TriangleVertexBufferID);
		glGenBuffers(1, &TriangleIndexBufferID);

		glBindBuffer(GL_ARRAY_BUFFER, TriangleVertexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, TriangleIndexBufferID);

		glBufferData(GL_ARRAY_BUFFER, (sizeof(Vector2D) * ShapeData::Triangle().vertices.size()), &ShapeData::Triangle().vertices.front(), GL_DYNAMIC_DRAW);//TODO: Remove dependecy on Shapedata class. Have a parameter that accepts vector or something similar to what original bindBuffer() accepts
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(uint16) * ShapeData::Triangle().indicies.size()), &ShapeData::Triangle().indicies.front(), GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, nullptr);
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

		glCompileShader(vertexShaderID);
		glCompileShader(FragmentShaderID);

		if (!BlazeFramework::OpenGL::CheckGLShaderStatus(vertexShaderID) || !BlazeFramework::OpenGL::CheckGLShaderStatus(FragmentShaderID))
			return;

		//Create GL Program
		programID = glCreateProgram();
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

	void sendUniformMat4Data(const char8* whatShaderVariableToSendTo, GLfloat* matrixData)
	{
		glUniformMatrix4fv(glGetUniformLocation(programID, whatShaderVariableToSendTo), 1, GL_FALSE, matrixData);
	}

	void Draw()
	{
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
	}
}
