#pragma once
#include <chrono>

class frameTimer
{
private:
	std::chrono::steady_clock::time_point last;

public: 
	frameTimer();
	float mark();
};

