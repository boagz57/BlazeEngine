#pragma once
#include "Universal/UniversalTypeDefs.h"

namespace BlazeFramework
{
	namespace OpenGL
	{
		bool RestartGLLogFile();

		//Log openGL messages/errors to GL log file
		bool LogToFile(const char8* message);
		bool LogToFile(const char8* message, const char8* stringToInsertInMessage);
		bool LogToFile(const char8* message, const char8* stringToInsertInMessage, int numberToInsertInMessage);
		bool LogToFile(const char8* message, int numberToInsertInMessage);

		//Log openGL messages/errors to BOTH log file and console
		bool LogToFileAndConsole(const char8* message);
		bool LogToFileAndConsole(const char8* message, const char8* string);
		bool LogToFileAndConsole(const char8* message, const char8* string, int number);
		bool LogToFileAndConsole(const char8* message, int number);
	}
}