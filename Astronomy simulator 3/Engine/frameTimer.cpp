#include "frameTimer.h"

frameTimer::frameTimer()
{
	last = std::chrono::steady_clock::now();
}

float frameTimer::mark()
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - old;

	return frameTime.count();
}
