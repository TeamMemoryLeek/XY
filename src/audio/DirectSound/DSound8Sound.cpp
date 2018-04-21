#include "DSound8Sound.h"

#include <assert.h>

DSound8Sound::DSound8Sound()
	: _buffer8(nullptr)
{
}

DSound8Sound::~DSound8Sound()
{
}

void DSound8Sound::play()
{
	assert(_buffer8 != nullptr);
	assert(SUCCEEDED(_buffer8->SetCurrentPosition(0)));
	assert(SUCCEEDED(_buffer8->Play(0, 0, 0)));
}

void DSound8Sound::stop()
{
	assert(_buffer8 != nullptr);
	assert(SUCCEEDED(_buffer8->Stop()));
}
