#include "AudioDecoder.h"

#include <assert.h>

AudioDecoder::AudioDecoder(const std::string& filename)
	: _soundDescription{}
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
		file) == sizeof(uint32_t));
	switch (signature)
	{
	case 0x52494646: // "RIFF"
		decodeRiff(file);
		break;
	default: assert(false);
	}

	fclose(file);
}

void AudioDecoder::decodeRiff(FILE* file)
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
		file) == sizeof(Header));
	switch (header.id)
	{
	case 0x57415645: // "WAVE"
		decodeRiffWave(file);
		break;
	default: assert(false);
	}
}

void AudioDecoder::decodeRiffWave(FILE* file)
{
	struct ChunkHeader
	{
		uint32_t id;
		uint32_t size;
	} header;

	while (fread_s(&header, sizeof(ChunkHeader), sizeof(ChunkHeader), 1, file)
		== sizeof(ChunkHeader))
	{
		switch (header.id)
		{
		case 0x666D7420: // "fmt "
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
				file) == sizeof(FormatChunk));

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
		case 0x64617461: // "data"
		{
			_data_size	= header.size;
			_data		= new uint8_t[header.size];

			assert(fread_s(
				&_data,
				_data_size,
				sizeof(uint8_t),
				_data_size,
				file) == _data_size);

			break;
		}
		default: fseek(file, header.size, SEEK_CUR);
		}
	}
}
