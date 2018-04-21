#pragma once
#include <string>

class SoundItf;

class AudioDeviceItf
{
public:
	virtual SoundItf* loadSound(const std::string& filename) = 0;
};
