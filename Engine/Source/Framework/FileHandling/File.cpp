#include "Precompiled.h"
#include "Macro.h"
#include "File.h"
#include <stdarg.h>
#include <stdio.h>

namespace BlazeFramework
{ 
	namespace FileHandling
	{
		File::File()
		{
		}

		File::File(char8* fileName) : 
			outputFile(outputFile = fopen(fileName, "w")), 
			M_FILENAME(fileName)
		{
		}

		File::~File()
		{
			fclose(outputFile);
		}

		void File::Close()
		{
			fclose(outputFile);
		}

		void File::Open(const char8* fileName, const char8* mode)
		{
			outputFile = fopen(fileName, mode);
		}

		bool File::Good()
		{
			if (!outputFile)
			{
				LOG("ERROR: could not open %s file for appending\n", M_FILENAME);
				return false;
			}

			return true;
		}

		void File::Write(const char8 * message, ...)
		{
			//Believe this captures the ellipsis parameter in your function
			va_list argptr;
			va_start(argptr, message);//Initializes the va_list

			vfprintf(outputFile, message, argptr);

			va_end(argptr);//Cleans up the va_list
		}

		void File::Write(const char8* message)
		{
			fprintf(outputFile, message);
		}
	}
}
