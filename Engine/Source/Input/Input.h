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

		void KeyPress();
	};
}


