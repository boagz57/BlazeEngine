#pragma once
#include "Framework/LowLevelInput/KeyboardHandling.h"

namespace BlazeInput
{
	class Keyboard
	{
	public:
		void ReadInput();
		static bool KeyPress(const uint16 key);
	};
}


