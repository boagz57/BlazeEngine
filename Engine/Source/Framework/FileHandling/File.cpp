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

		File::File(char8* pFileName) : 
			pOutputFile(pOutputFile = fopen(pFileName, "w")), 
			cpFilename(pFileName)
		{
		}

		File::~File()
		{
			fclose(pOutputFile);
		}

		void File::Close()
		{
			fclose(pOutputFile);
		}

		void File::Open(const char8* cFileName, const char8* mode)
		{
			pOutputFile = fopen(cFileName, mode);
		}

		bool File::Good()
		{
			if (!pOutputFile)
			{
				LOG("ERROR: could not open %s file for appending\n", this->cpFilename);
				return false;
			}

			return true;
		}

		void File::Write(const char8 * cpMessage, ...)
		{
			//Believe this captures the ellipsis parameter in your function
			va_list argptr;
			va_start(argptr, cpMessage);//Initializes the va_list

			vfprintf(pOutputFile, cpMessage, argptr);

			va_end(argptr);//Cleans up the va_list
		}

		void File::Write(const char8* cpMessage)
		{
			fprintf(pOutputFile, cpMessage);
		}
	}
}
