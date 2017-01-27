#pragma once
#include "Framework/LowLevelInput/KeyboardHandling.h"

namespace BlazeInput
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		static bool KeyPress(const uint16 key);
	};
}


