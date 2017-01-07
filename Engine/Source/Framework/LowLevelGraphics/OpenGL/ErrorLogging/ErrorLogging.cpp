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

		bool LogToFile(const char8* cMessage)
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

		bool LogToFile(const char8* cMessage, const char8* cString)
		{
			FileHandling::File glLogFile;
			glLogFile.Open(GL_LOG_FILE, "a");

			if (!glLogFile.Good())
			{
				LOG("ERROR: could not open %s file for appending\n", GL_LOG_FILE);
				return false;
			}

			glLogFile.Write(cMessage, cString);

			return true;
		}

		bool LogToFile(const char8 * cMessage, const char8* cStringToInsertInMessage, int numberToInsertInMessage)
		{
			FileHandling::File glLogFile(GL_LOG_FILE);
			if (!glLogFile.Good())
			{
				LOG("ERROR: could not open %s file for appending\n", GL_LOG_FILE);
				return false;
			}

			glLogFile.Write(cMessage, cStringToInsertInMessage, numberToInsertInMessage);

			return true;
		}

		bool LogToFile(const char8 * cMessage, int numberToInsertInMessage)
		{
			FileHandling::File glLogFile(GL_LOG_FILE);
			if (!glLogFile.Good())
			{
				LOG("ERROR: could not open %s file for appending\n", GL_LOG_FILE);
				return false;
			}

			glLogFile.Write(cMessage, numberToInsertInMessage);

			return true;
		}

		bool LogToFileAndConsole(const char8* cMessage)//TODO: Convert to my File system
		{
			FILE* glLogFile = fopen(GL_LOG_FILE, "a");
			if (!glLogFile)
			{
				fprintf(stderr, "ERROR: could not open %s file for appending\n", GL_LOG_FILE);
				return false;
			}

			//Prints to log file
			fprintf(glLogFile, cMessage);
			//Prints to console
			fprintf(stderr, cMessage);

			fclose(glLogFile);

			return true;
		}

		bool LogToFileAndConsole(const char8 * cMessage, const char8 * cString)//TODO: Convert to my File system
		{
			FILE* glLogFile = fopen(GL_LOG_FILE, "a");
			if (!glLogFile)
			{
				fprintf(stderr, "ERROR: could not open %s file for appending\n", GL_LOG_FILE);
				return false;
			}

			//Prints to log file
			fprintf(glLogFile, cMessage, cString);
			//Prints to console
			fprintf(stderr, cMessage, cString);

			fclose(glLogFile);

			return true;
		}

		bool LogToFileAndConsole(const char8 * cMessage, const char8 * cString, int number)//TODO: Convert to my file system
		{
			FILE* glLogFile = fopen(GL_LOG_FILE, "a");
			if (!glLogFile)
			{
				fprintf(stderr, "ERROR: could not open %s file for appending\n", GL_LOG_FILE);
				return false;
			}

			//Prints to log file
			fprintf(glLogFile, cMessage, cString, number);
			//Prints to console
			fprintf(stderr, cMessage, cString, number);

			fclose(glLogFile);

			return true;
		}

		bool LogToFileAndConsole(const char8 * cMessage, int number)//TODO: Convert to my file system
		{
			FILE* glLogFile = fopen(GL_LOG_FILE, "a");
			if (!glLogFile)
			{
				fprintf(stderr, "ERROR: could not open %s file for appending\n", GL_LOG_FILE);
				return false;
			}

			//Prints to log file
			fprintf(glLogFile, cMessage, number);
			//Prints to console
			fprintf(stderr, cMessage, number);

			fclose(glLogFile);

			return true;
		}
	}
}