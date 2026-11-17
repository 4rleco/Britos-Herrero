#include "Timer.h"

#include <iostream>

float Timer::deltaTime = 0.0f;
TimePoint Timer::previous;
TimePoint Timer::current;
Miliseconds Timer::delta;

Timer::Timer()
{

}

Timer::~Timer()
{

}

void Timer::InitClock()
{
	previous = Clock::now();
}

void Timer::UpdateDeltaTime()
{
	current = Clock::now();
	delta = current - previous;
	previous = current;

	deltaTime = delta.count();
}

float Timer::GetDeltaTime()
{
	return deltaTime;
}
