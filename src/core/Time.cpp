#include "Time.h"
#include <chrono>

namespace xy
{

double Time::deltaTime = 0.0;
double Time::time = 0.0;
double Time::_lastTime = 0.0;

static uint64_t micros()
{
	uint64_t us = std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	return us;
}

void Time::initialize()
{
	_lastTime = (double)micros() / 1000000.0;
}

void Time::update()
{
	double now = (double)micros() / 1000000.0;
	deltaTime = now - _lastTime;
	time += deltaTime;
	_lastTime = now;
}

}