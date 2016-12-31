#pragma once
#include "Macro.h"
#include "UniversalTypeDefs.h"
#include "GL/glew.h"
#include <iostream>
#include <fstream>

namespace MyOpenGL
{
	void Initialize();
	void InitializeGLBuffers();
	void MoveTriangle(float x, float y);
	bool CheckShaderStatus(GLuint shaderID);
	bool CheckProgramStatus(GLuint programID);
	std::string ReadShaderCode(const char8* fileName);
	void InstallShaders();

	bool RestartGLLogFile();

	//Log openGL messages/erros to log file
	bool GlLogToFile(const char8* message);
	bool GlLogToFile(const char8* message, const char8* stringToInsertInMessage);
	bool GlLogToFile(const char8* message, const char8* stringToInsertInMessage, int numberToInsertInMessage);
	bool GlLogToFile(const char8* message, int numberToInsertInMessage);

	//Log openGL messages/errors to BOTH log file and console
	bool GlLogError(const char8* message);
	bool GlLogError(const char8* message, const char8* string);
	bool GlLogError(const char8* message, const char8* string, int number);
	bool GlLogError(const char8* message, int number);
}
