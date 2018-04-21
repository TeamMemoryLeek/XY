#pragma once
#include "audio/SoundItf.h"

#include <string>

#include <xaudio2.h>

class XAudio2Sound : public SoundItf
{
	friend class XAudio2Device;

public:
	XAudio2Sound();
	~XAudio2Sound();

	void play() override;
	void stop() override;

private:
	IXAudio2SourceVoice*	_sourceVoice;
	uint8_t*				_buffer;
	size_t					_bufferSize;
};
