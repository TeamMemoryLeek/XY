#pragma once
#include <string>
#include <vector>

enum class AudioFormat
{
	UNKNOWN = 0,
	WAVE,
};

enum class AudioCompression
{
	UNKNOWN = 0,
	UNCOMPRESSED_PCM,
	COMPRESSED,
};

class AudioDecoder
{
public:
	AudioDecoder(const std::string& filename, uint8_t** outData);

	AudioCompression	getCompression()	const { return _compression; }
	uint32_t			getNumChannels()	const { return _numChannels; }
	uint32_t			getSampleRate()		const { return _sampleRate; }
	uint32_t			getByteRate()		const { return _byteRate; }
	uint32_t			getBlockAlign()		const { return _blockAlign; }
	uint32_t			getBitsPerSample()	const { return _bitsPerSample; }
	size_t				getDataSize()		const { return _data_size; }

private:
	void decodeRiff(FILE* file, uint8_t** outData);
	void decodeRiffWave(FILE* file, uint8_t** outData);

	AudioFormat			_format;
	AudioCompression	_compression;
	uint32_t			_numChannels;
	uint32_t			_sampleRate;
	uint32_t			_byteRate;
	uint32_t			_blockAlign;
	uint32_t			_bitsPerSample;
	size_t				_data_size;
};
