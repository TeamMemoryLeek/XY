#pragma once
#include <Windows.h>

#include "audio/AudioDeviceItf.h"

class WinMMDevice : public AudioDeviceItf
{
public:
	SoundItf* loadSound(const std::string& filename) override;
};
