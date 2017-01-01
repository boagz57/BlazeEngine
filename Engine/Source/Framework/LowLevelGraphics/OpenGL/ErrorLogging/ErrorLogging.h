#pragma once
#include "../../../../Universal/UniversalTypeDefs.h"

namespace BlazeFramework
{
	namespace OpenGL
	{
		bool RestartGLLogFile();

		//Log openGL messages/errors to log file
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
}