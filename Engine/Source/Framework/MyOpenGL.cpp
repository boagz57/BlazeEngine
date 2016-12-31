#include "Precompiled.h"
#include "Macro.h"
#include "UniversalTypeDefs.h"
#include <fstream>
#include "GL/glew.h"
#include "MyOpenGL.h"
#include <stdarg.h>
#include "FileHandling/File.h"
#include <ctime>
#include "Math/Vector3D/Vector3D.h"
#include "../Universal/Globals.h"

#define GL_LOG_FILE "gl.log"

namespace MyOpenGL
{
	using namespace BlazeFramework;
	using namespace Math;

	Vector3D triangle[] =
	{
		Vector3D(+0.0f, +0.2f, 0.0f),
		Vector3D(-0.1f, 0.0f, 0.0f),
		Vector3D(+0.1f, 0.0f, 0.0f)
	};

	void Initialize()
	{
		engineClock.Initialize();
	}

	void InitializeGLBuffers()
	{
		GLuint bufferID;
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
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

	void MoveTriangle(float x, float y)
	{
		Vector3D velocity(x, y, 0.0f);

		for (int i = 0; i < 3; i++)
		{
			triangle[i] = triangle[i] + velocity * engineClock.TimeSinceLastFrame();
		};

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(triangle), triangle);
	}

	bool CheckShaderStatus(GLuint shaderID)
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

	bool CheckProgramStatus(GLuint programID)
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

	std::string ReadShaderCode(const char8* shaderFilePath, const char8* typeOfShader)
	{
		std::ifstream shaderFileInputStream(shaderFilePath);
		if (!shaderFileInputStream.good())
		{
			LOG("%s Shader File failed to load!\n", typeOfShader);
		};

		return std::string(std::istreambuf_iterator<char8>(shaderFileInputStream), std::istreambuf_iterator<char8>());
	}

	void InstallShaders()
	{
		//Create Shader
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		//Add source or text file to shader object
		std::string temp = ReadShaderCode("../Engine/Source/Graphics/Shaders/VertexShader.glsl", "Vertex").c_str();
		const GLchar* adapter[1];

		adapter[0] = temp.c_str();
		glShaderSource(vertexShaderID, 1, adapter, 0);
		temp = ReadShaderCode("../Engine/Source/Graphics/Shaders/FragmentShader.glsl", "Fragment").c_str();
		adapter[0] = temp.c_str();
		glShaderSource(FragmentShaderID, 1, adapter, 0);

		//Compile Shadaer
		glCompileShader(vertexShaderID);
		glCompileShader(FragmentShaderID);

		if (!CheckShaderStatus(vertexShaderID) || !CheckShaderStatus(FragmentShaderID))
			return;

		//Create Program
		GLuint programID = glCreateProgram();
		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, FragmentShaderID);

		//Link Program
		glLinkProgram(programID);

		if (!CheckProgramStatus(programID))
		{
			LOG("Failed to link program");
			return;
		}

		//Use program
		glUseProgram(programID);
	}

	bool RestartGLLogFile()
	{
		//Will create a NEW gl.log file, or replace old one, each compilation. Will use this log file to dump opengl info into to help with debugging
		FileHandling::File glLogFile(GL_LOG_FILE);
		if (!glLogFile.Good())
		{
			LOG("ERROR: could not open GL_LOG_FILE log file %s for writing\n", GL_LOG_FILE);
			return false;
		}

		time_t rawtime = time(&rawtime);
		tm *timeinfo = localtime(&rawtime);

		//Print day and time to top of log file
		glLogFile.Write("%i-%i-%i  %i:%i:%i\n\n", timeinfo->tm_mon, timeinfo->tm_mday, timeinfo->tm_year, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

		glLogFile.Close();

		return true;
	}

	bool GlLogToFile(const char8* message)
	{
		FileHandling::File glLogFile(GL_LOG_FILE);
		if (!glLogFile.Good())
		{
			LOG("ERROR: could not open %s file for appending\n", GL_LOG_FILE);
			return false;
		}

		glLogFile.Close();

		return true;
	}

	bool GlLogToFile(const char8* message, const char8* string)
	{
		FileHandling::File glLogFile;
		glLogFile.Open(GL_LOG_FILE, "a");

		if (!glLogFile.Good())
		{
			LOG("ERROR: could not open %s file for appending\n", GL_LOG_FILE);
			return false;
		}

		glLogFile.Write(message, string);

		return true;
	}

	bool GlLogToFile(const char8 * message, const char8* stringToInsertInMessage, int numberToInsertInMessage)
	{
		FileHandling::File glLogFile(GL_LOG_FILE);
		if (!glLogFile.Good())
		{
			LOG("ERROR: could not open %s file for appending\n", GL_LOG_FILE);
			return false;
		}

		glLogFile.Write(message, stringToInsertInMessage, numberToInsertInMessage);

		return true;
	}

	bool GlLogToFile(const char8 * message, int numberToInsertInMessage)
	{
		FileHandling::File glLogFile(GL_LOG_FILE);
		if (!glLogFile.Good())
		{
			LOG("ERROR: could not open %s file for appending\n", GL_LOG_FILE);
			return false;
		}

		glLogFile.Write(message, numberToInsertInMessage);

		return true;
	}

	bool GlLogError(const char8* message)//TODO: Convert to my File system
	{
		FILE* glLogFile = fopen(GL_LOG_FILE, "a");
		if (!glLogFile)
		{
			fprintf(stderr, "ERROR: could not open %s file for appending\n", GL_LOG_FILE);
			return false;
		}

		//Prints to log file
		fprintf(glLogFile, message);
		//Prints to console
		fprintf(stderr, message);

		fclose(glLogFile);

		return true;
	}

	bool GlLogError(const char8 * message, const char8 * string)//TODO: Convert to my File system
	{
		FILE* glLogFile = fopen(GL_LOG_FILE, "a");
		if (!glLogFile)
		{
			fprintf(stderr, "ERROR: could not open %s file for appending\n", GL_LOG_FILE);
			return false;
		}

		//Prints to log file
		fprintf(glLogFile, message, string);
		//Prints to console
		fprintf(stderr, message, string);

		fclose(glLogFile);

		return true;
	}

	bool GlLogError(const char8 * message, const char8 * string, int number)//TODO: Convert to my file system
	{
		FILE* glLogFile = fopen(GL_LOG_FILE, "a");
		if (!glLogFile)
		{
			fprintf(stderr, "ERROR: could not open %s file for appending\n", GL_LOG_FILE);
			return false;
		}

		//Prints to log file
		fprintf(glLogFile, message, string, number);
		//Prints to console
		fprintf(stderr, message, string, number);

		fclose(glLogFile);

		return true;
	}

	bool GlLogError(const char8 * message, int number)//TODO: Convert to my file system
	{
		FILE* glLogFile = fopen(GL_LOG_FILE, "a");
		if (!glLogFile)
		{
			fprintf(stderr, "ERROR: could not open %s file for appending\n", GL_LOG_FILE);
			return false;
		}

		//Prints to log file
		fprintf(glLogFile, message, number);
		//Prints to console
		fprintf(stderr, message, number);

		fclose(glLogFile);

		return true;
	}
}
