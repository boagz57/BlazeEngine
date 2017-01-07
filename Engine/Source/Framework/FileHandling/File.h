#pragma once
#include "Universal/UniversalTypeDefs.h"

namespace BlazeFramework
{
	namespace FileHandling
	{
		class File
		{
		public:
			File();
			//Opens or creates(if not already created) a file for writing
			File(char8* fileName);
			~File();

			void Close();
			void Open(const char8* fileName, const char8* mode);
			bool Good();

			void Write(const char8* message, ...);
			void Write(const char8* message);
		private:
			const char8* M_FILENAME;
			FILE* outputFile;
		};
	}
}
