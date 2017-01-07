#include "Precompiled.h"
#include "Universal/Macro.h"
#include "Universal/UniversalTypeDefs.h"
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
			mOutputFile(mOutputFile = fopen(fileName, "w")), 
			cmFilename(fileName)
		{
		}

		File::~File()
		{
			fclose(mOutputFile);
		}

		void File::Close()
		{
			fclose(mOutputFile);
		}

		void File::Open(const char8* fileName, const char8* mode)
		{
			mOutputFile = fopen(fileName, mode);
		}

		bool File::Good()
		{
			if (!mOutputFile)
			{
				LOG("ERROR: could not open %s file for appending\n", cmFilename);
				return false;
			}

			return true;
		}

		void File::Write(const char8 * message, ...)
		{
			//Believe this captures the ellipsis parameter in your function
			va_list argptr;
			va_start(argptr, message);//Initializes the va_list

			vfprintf(mOutputFile, message, argptr);

			va_end(argptr);//Cleans up the va_list
		}

		void File::Write(const char8* message)
		{
			fprintf(mOutputFile, message);
		}
	}
}
