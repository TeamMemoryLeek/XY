#pragma once

namespace xy
{

class Time
{
public:
	static double deltaTime;
	static double time;

private:
	static void initialize();
	static void update();

	static double _lastTime;

	friend class Core;
};

}