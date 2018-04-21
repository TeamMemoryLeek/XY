#include "DSound8Device.h"

#include <assert.h>

#include "audio/AudioDecoder.h"
#include "audio/DirectSound/DSound8Sound.h"

DSound8Device::DSound8Device()
{
	assert(SUCCEEDED(DirectSoundCreate8(nullptr, &_device, nullptr)));
	assert(SUCCEEDED(_device->SetCooperativeLevel(
		GetConsoleWindow(),
		DSSCL_PRIORITY)));

	DSBUFFERDESC primaryBufferDesc	= {};
	primaryBufferDesc.dwSize		= sizeof(DSBUFFERDESC);
	primaryBufferDesc.dwFlags		= DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;

	assert(SUCCEEDED(_device->CreateSoundBuffer(
		&primaryBufferDesc,
		&_primaryBuffer,
		nullptr)));
}

DSound8Device::~DSound8Device()
{
	if (_primaryBuffer)
		_primaryBuffer->Release();

	if (_device)
		_device->Release();
}

SoundItf* DSound8Device::loadSound(const std::string& filename)
{
	DSound8Sound*	sound		= new DSound8Sound;
	uint8_t*		soundData	= nullptr;
	AudioDecoder	decoder(filename, &soundData);

	WAVEFORMATEX format		= {};
	format.wFormatTag		= WAVE_FORMAT_PCM;
	format.nChannels		= decoder.getNumChannels();
	format.nSamplesPerSec	= decoder.getSampleRate();
	format.nAvgBytesPerSec	= decoder.getByteRate();
	format.nBlockAlign		= decoder.getBlockAlign();
	format.wBitsPerSample	= decoder.getBitsPerSample();

	DSBUFFERDESC bufferDesc		= {};
	bufferDesc.dwSize			= sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags			= DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes	= decoder.getDataSize();
	bufferDesc.lpwfxFormat		= &format;

	IDirectSoundBuffer* tempBuffer;
	assert(SUCCEEDED(_device->CreateSoundBuffer(
		&bufferDesc,
		&tempBuffer,
		nullptr)));

	assert(SUCCEEDED(tempBuffer->QueryInterface(
		IID_IDirectSoundBuffer8,
		(void**)&sound->_buffer8)));

	tempBuffer->Release();

	void* bufferPtr;
	DWORD bufferSize;
	assert(SUCCEEDED(sound->_buffer8->Lock(
		0,
		decoder.getDataSize(),
		&bufferPtr,
		&bufferSize,
		nullptr,
		nullptr,
		0)));

	std::memcpy(bufferPtr, soundData, decoder.getDataSize());

	assert(SUCCEEDED(sound->_buffer8->Unlock(
		bufferPtr,
		bufferSize,
		nullptr,
		0)));

	sound->_buffer8->SetVolume(DSBVOLUME_MAX);

	return sound;
}
