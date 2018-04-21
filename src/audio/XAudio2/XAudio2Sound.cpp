#include "XAudio2Sound.h"

#include <assert.h>

XAudio2Sound::XAudio2Sound()
	: _sourceVoice(nullptr)
	, _buffer(nullptr)
	, _bufferSize(0)
{
}

XAudio2Sound::~XAudio2Sound()
{
}

void XAudio2Sound::play()
{
	assert(_sourceVoice != nullptr);
	_sourceVoice->Start();
}

void XAudio2Sound::stop()
{
	assert(_sourceVoice != nullptr);
	_sourceVoice->Stop();
}
