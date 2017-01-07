#include "Precompiled.h"
#include "Universal/Macro.h"
#include <ctime>
#include <stdarg.h>
#include <fstream>
#include "FileHandling/File.h"
#include "ErrorLogging.h"

#define GL_LOG_FILE "gl.log"

namespace BlazeFramework
{
	namespace OpenGL
	{
		bool RestartGLLogFile()
		{
			//Will create a NEW gl.log file, or replace old one, each compilation. 
			//Will use this log file to dump opengl info into to help with debugging
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

		bool LogToFile(const char8* message)
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

		bool LogToFile(const char8* message, const char8* string)
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

		bool LogToFile(const char8 * message, const char8* stringToInsertInMessage, int numberToInsertInMessage)
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

		bool LogToFile(const char8 * message, int numberToInsertInMessage)
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

		bool LogToFileAndConsole(const char8* message)//TODO: Convert to my File system
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

		bool LogToFileAndConsole(const char8 * message, const char8 * string)//TODO: Convert to my File system
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

		bool LogToFileAndConsole(const char8 * message, const char8 * string, int number)//TODO: Convert to my file system
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

		bool LogToFileAndConsole(const char8 * message, int number)//TODO: Convert to my file system
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
}