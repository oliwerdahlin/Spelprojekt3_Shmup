#pragma once
#include "pch.h"
#include "Timer.h"
using Clock = std::chrono::high_resolution_clock;
void CommonUtilities::Timer::TUpdate()
{
	std::chrono::duration<double, std::ratio<1, 1>> deltaTime = Clock::now() - myFrameStart;
	myDeltaTime = static_cast<float>(deltaTime.count());
	myFrameStart = Clock::now();
}
float CommonUtilities::Timer::TGetDeltaTime() const
{
	return myDeltaTime;
}
double CommonUtilities::Timer::TGetTotalTime() const
{
	std::chrono::duration<double, std::ratio<1, 1>> totalTime = myFrameStart - myBegin;
	return totalTime.count();
}
