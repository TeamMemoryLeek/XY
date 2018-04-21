#pragma once
#include "audio/AudioDeviceItf.h"

#include <dsound.h>

class DSound8Device : public AudioDeviceItf
{
public:
	DSound8Device();
	~DSound8Device();

	SoundItf* loadSound(const std::string& filename) override;

private:
	IDirectSound8*		_device;
	IDirectSoundBuffer*	_primaryBuffer;
};
