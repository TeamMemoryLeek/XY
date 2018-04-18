#pragma once

namespace xy
{

class Keyboard
{
public:
	static bool getKeyDown(int key);
	static bool getKeyUp(int key);
	static bool getKey(int key);

private:
	static void initialize();
	static void update();

	static const unsigned int NUM_KEYS = 256;
	static bool _keys[NUM_KEYS];
	static bool _keysPrev[NUM_KEYS];

	static void keyCallback(int action, int key);

	friend class Core;
};

}