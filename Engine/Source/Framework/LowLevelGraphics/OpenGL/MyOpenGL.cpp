#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Universal/UniversalTypeDefs.h"
#include <fstream>
#include "GL/glew.h"
#include "MyOpenGL.h"
#include "DataStructures/Vector.h"
#include "Math/Vector3D.h"
#include "Universal/Globals.h"
#include "StatusChecks/StatusChecks.h"

GLuint triangleVertexBufferID;
GLuint triangleIndexBufferID;

GLuint squareVertexBufferID;
GLuint squareIndexBufferID;

static GLuint programID;

namespace MyOpenGL
{
	using namespace BlazeFramework;

	void InitializeBuffers(int64 sizeOfGeometry, const void* GeometryDataFirstElement, int64 sizeOfIndicies, const void* indicieDataFirstElement, uint32* vertexBufferID, uint32* indexBufferID)
	{
		glGenBuffers(1, vertexBufferID);
		glGenBuffers(1, indexBufferID);

		glBindBuffer(GL_ARRAY_BUFFER, *vertexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *indexBufferID);

		glBufferData(GL_ARRAY_BUFFER, (sizeof(Vector3D) * sizeOfGeometry), GeometryDataFirstElement, GL_DYNAMIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(uint16) * sizeOfIndicies), indicieDataFirstElement, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, nullptr);
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

	void sendUniformVec2Data(const char8 * whatShaderVariableToSendTo, GLfloat * matrixData)
	{
		glUniform2fv(glGetUniformLocation(programID, whatShaderVariableToSendTo), 1, matrixData);
	}

	void Draw(uint32 vertexBufferID, uint32 indexBufferID, uint16 numOfIndicies)
	{
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, nullptr);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);

		glDrawElements(GL_TRIANGLES, numOfIndicies, GL_UNSIGNED_SHORT, 0);
	}
}
