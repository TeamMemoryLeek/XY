#include "Keyboard.h"

#include <string.h>

namespace xy
{

bool Keyboard::_keys[NUM_KEYS];
bool Keyboard::_keysPrev[NUM_KEYS];

// TODO: Error if unknown key is pressed

bool Keyboard::getKeyDown(int key)
{
	return _keys[key] && !_keysPrev[key];
}

bool Keyboard::getKeyUp(int key)
{
	return !_keys[key] && _keysPrev[key];
}

bool Keyboard::getKey(int key)
{
	return _keys[key];
}

void Keyboard::initialize()
{
	memset(&_keys, false, sizeof(_keys));
	memset(&_keysPrev, false, sizeof(_keysPrev));
}

void Keyboard::update()
{
	memcpy(&_keysPrev, &_keys, sizeof(_keys));
}

void Keyboard::keyCallback(int action, int key)
{
	if (key < 0 || key >= NUM_KEYS)
		return;

	if (action == 0) // Down
		_keys[key] = true;
	else if (action == 1) // Up
		_keys[key] = false;
}

}