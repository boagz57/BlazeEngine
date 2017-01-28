#pragma once
#include "Framework/LowLevelInput/KeyboardHandling.h"

namespace BlazeInput
{
	class Input
	{
	public:
		Input();
		~Input();

		bool Initialize();
		bool Shutdown();

		static bool KeyPress(const uint16 key);
	};
}


