#pragma once
#include <chrono>
#include "Universal/UniversalTypeDefs.h"

namespace Timing
{
	class Clock
	{
	public:
		Clock();

		void Initialize();
		bool ShutDown();
		void NewFrame();
		sfloat TimeSinceLastFrame();

	private:
		sfloat DeltaTime;
		std::chrono::time_point<std::chrono::steady_clock> TimePointLastFrame;
	};
}
