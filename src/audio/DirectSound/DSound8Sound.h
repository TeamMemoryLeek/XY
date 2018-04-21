#pragma once
#include "audio/SoundItf.h"

#include <string>

#include <dsound.h>

class DSound8Sound : public SoundItf
{
	friend class DSound8Device;

public:
	DSound8Sound();
	~DSound8Sound();

	void play() override;
	void stop() override;

private:
	IDirectSoundBuffer8* _buffer8;
};
