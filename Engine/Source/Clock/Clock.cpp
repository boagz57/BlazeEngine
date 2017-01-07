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
		mTimePointLastFrame = high_resolution_clock::now();
	}

	bool Clock::ShutDown()
	{
		return true;
	}

	void Clock::NewFrame()
	{
		auto timePointThisFrame = high_resolution_clock::now();
		auto timeDifference = timePointThisFrame - mTimePointLastFrame;
		mDeltaTime = ((sfloat)timeDifference.count()) * .000000001f;
		mTimePointLastFrame = timePointThisFrame;
	}

	sfloat Clock::TimeSinceLastFrame()
	{
		return mDeltaTime;
	}
}

//Global object declaration/intialization. Can be found in Globals.h
Timing::Clock engineClock;
