#pragma once
#include "LowLevelInput/KeyboardHandling.h"
#include <map>

namespace BlazeInput
{
	class Input
	{
	public:

	protected:

	private:

		////////////////////////////////////////////////////////////////////////////

	public:
		Input();
		~Input();

		bool Initialize();
		bool Shutdown();

		void BindKey(uint16 key, void(*keyHandlerFunc)());
		void UseInput();

	protected:

	private:
		std::map<const uint16, void (*)()> keyMap;
	};
}


