#include "Precompiled.h"
#include <chrono>
#include "Clock.h"
#include "../Universal/Globals.h"

namespace Timing
{
	using namespace std::chrono;

	Clock::Clock()
	{
	}

	void Clock::Initialize()
	{
		timePointLastFrame = high_resolution_clock::now();
	}

	bool Clock::ShutDown()
	{
		return true;
	}

	void Clock::NewFrame()
	{
		auto timePointThisFrame = high_resolution_clock::now();
		auto timeDifference = timePointThisFrame - timePointLastFrame;
		deltaTime = ((float)timeDifference.count()) * .000000001f;
		timePointLastFrame = timePointThisFrame;
	}

	float Clock::TimeSinceLastFrame()
	{
		return deltaTime;
	}
}

//Global object declaration/intialization. Can be found in Globals.h
Timing::Clock engineClock;
