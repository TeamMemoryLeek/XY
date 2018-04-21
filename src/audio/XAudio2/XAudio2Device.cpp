#include "XAudio2Device.h"

#include <assert.h>

#include "audio/AudioDecoder.h"
#include "audio/XAudio2/XAudio2Sound.h"

XAudio2Device::XAudio2Device()
	: _device(nullptr)
{
	assert(SUCCEEDED(XAudio2Create(&_device, 0, XAUDIO2_DEFAULT_PROCESSOR)));
	assert(SUCCEEDED(_device->CreateMasteringVoice(&_masterVoice)));
}

XAudio2Device::~XAudio2Device()
{
}

SoundItf* XAudio2Device::loadSound(const std::string& filename)
{
	XAudio2Sound* sound = new XAudio2Sound;

	AudioDecoder audioDecoder(filename, &sound->_buffer);
	assert(audioDecoder.getCompression() == AudioCompression::UNCOMPRESSED_PCM);
	sound->_bufferSize = audioDecoder.getDataSize();

	WAVEFORMATEX sourceFormat		= {};
	sourceFormat.wFormatTag			= WAVE_FORMAT_PCM;
	sourceFormat.nChannels			= audioDecoder.getNumChannels();
	sourceFormat.nSamplesPerSec		= audioDecoder.getSampleRate();
	sourceFormat.nAvgBytesPerSec	= audioDecoder.getByteRate();
	sourceFormat.nBlockAlign		= audioDecoder.getBlockAlign();
	sourceFormat.wBitsPerSample		= audioDecoder.getBitsPerSample();
	sourceFormat.cbSize				= sizeof(WAVEFORMATEX);

	assert(SUCCEEDED(_device->CreateSourceVoice(
		&sound->_sourceVoice,
		&sourceFormat)));

	XAUDIO2_BUFFER buffer	= {};
	buffer.AudioBytes		= audioDecoder.getDataSize();
	buffer.pAudioData		= sound->_buffer;

	assert(SUCCEEDED(sound->_sourceVoice->SubmitSourceBuffer(&buffer)));

	return sound;
}
