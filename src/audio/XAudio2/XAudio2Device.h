#pragma once
#include "audio/AudioDeviceItf.h"

#include <xaudio2.h>

class XAudio2Device : public AudioDeviceItf
{
public:
	XAudio2Device();
	~XAudio2Device();

	SoundItf* loadSound(const std::string& filename) override;

private:
	IXAudio2*				_device;
	IXAudio2MasteringVoice*	_masterVoice;
};
