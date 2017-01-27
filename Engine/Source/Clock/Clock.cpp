#include "Precompiled.h"
#include <chrono>
#include "Clock.h"
#include "Universal/UniversalTypeDefs.h"
#include "Universal/Globals.h"

namespace Timing
{
	using namespace std::chrono;

	Clock::Clock()
	{
	}

	void Clock::Initialize()
	{
		TimePointLastFrame = high_resolution_clock::now();
	}

	bool Clock::ShutDown()
	{
		return true;
	}

	void Clock::NewFrame()
	{
		auto timePointThisFrame = high_resolution_clock::now();
		auto timeDifference = timePointThisFrame - TimePointLastFrame;
		DeltaTime = ((sfloat)timeDifference.count()) * .000000001f;
		TimePointLastFrame = timePointThisFrame;
	}

	sfloat Clock::TimeSinceLastFrame()
	{
		return DeltaTime;
	}
}

//Global object declaration/intialization. Can be found in Globals.h
Timing::Clock engineClock;
