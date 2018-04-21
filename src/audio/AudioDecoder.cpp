#include "AudioDecoder.h"

#include <assert.h>

// #TODO: Fix byte ordering on ID constants. currently little endian.

AudioDecoder::AudioDecoder(const std::string& filename, uint8_t** outData)
: _format(AudioFormat::UNKNOWN)
, _compression(AudioCompression::UNKNOWN)
, _numChannels(0)
, _sampleRate(0)
, _byteRate(0)
, _blockAlign(0)
, _bitsPerSample(0)
, _dataSize(0)
{
	FILE* file;
	assert(fopen_s(&file, filename.c_str(), "rb") == 0);

	// Read signature and determine how to decode the file data
	uint32_t signature;
	assert(fread_s(
		&signature,
		sizeof(uint32_t),
		sizeof(uint32_t),
		1,
		file) == 1);
	switch (signature)
	{
	case 0x46464952: // "RIFF"
		decodeRiff(file, outData);
		break;
	default: assert(false);
	}

	fclose(file);
}

void AudioDecoder::decodeRiff(FILE* file, uint8_t** outData)
{
	struct Header
	{
		uint32_t chunkSize;
		uint32_t id;
	} header;

	// Read the header and determine how to decode the riff data
	assert(fread_s(
		&header,
		sizeof(Header),
		sizeof(Header),
		1,
		file) == 1);
	switch (header.id)
	{
	case 0x45564157: // "WAVE"
		_format = AudioFormat::WAVE;
		decodeRiffWave(file, outData);
		break;
	default: assert(false);
	}
}

void AudioDecoder::decodeRiffWave(FILE* file, uint8_t** outData)
{
	struct ChunkHeader
	{
		uint32_t id;
		uint32_t size;
	} header;

	while (fread_s(&header, sizeof(ChunkHeader), sizeof(ChunkHeader), 1, file)
		== 1)
	{
		switch (header.id)
		{
		case 0x20746D66: // "fmt "
		{
			struct FormatChunk
			{
				uint16_t audioFormat;
				uint16_t numChannels;
				uint32_t sampleRate;
				uint32_t byteRate;
				uint16_t blockAlign;
				uint16_t bitsPerSample;
			} formatChunk;

			assert(fread_s(
				&formatChunk,
				sizeof(FormatChunk),
				sizeof(FormatChunk),
				1,
				file) == 1);

			_compression	= (formatChunk.audioFormat == 1) ?
				AudioCompression::UNCOMPRESSED_PCM :
				AudioCompression::COMPRESSED;
			_numChannels	= formatChunk.numChannels;
			_sampleRate		= formatChunk.sampleRate;
			_byteRate		= formatChunk.byteRate;
			_blockAlign		= formatChunk.blockAlign;
			_bitsPerSample	= formatChunk.bitsPerSample;

			break;
		}
		case 0x61746164: // "data"
		{
			_dataSize	= header.size;
			*outData	= new uint8_t[header.size];

			assert(fread_s(
				*outData,
				_dataSize,
				sizeof(uint8_t),
				_dataSize,
				file) == _dataSize);

			break;
		}
		default: fseek(file, header.size, SEEK_CUR);
		}
	}
}
