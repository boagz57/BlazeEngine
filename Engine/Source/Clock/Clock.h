#pragma once
#include <chrono>

namespace Timing
{
	class Clock
	{
	public:
		Clock();

		void Initialize();
		bool ShutDown();
		void NewFrame();
		float TimeSinceLastFrame();

	private:
		float deltaTime;
		std::chrono::time_point<std::chrono::steady_clock> timePointLastFrame;
	};
}
