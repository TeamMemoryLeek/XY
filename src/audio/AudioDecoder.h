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
	UNCOMPRESSED_PCM,
	COMPRESSED,
};

class AudioDecoder
{
public:
	AudioDecoder(const std::string& filename);
	~AudioDecoder();

	AudioCompression	getCompression()	const { return _compression; }
	uint32_t			getNumChannels()	const { return _numChannels; }
	uint32_t			getSampleRate()		const { return _sampleRate; }
	uint32_t			getByteRate()		const { return _byteRate; }
	uint32_t			getBlockAlign()		const { return _blockAlign; }
	uint32_t			getBitsPerSample()	const { return _bitsPerSample; }
	const uint8_t*		getData()			const { return _data; }
	size_t				getDataSize()		const { return _data_size; }

private:
	void decodeRiff(FILE* file);
	void decodeRiffWave(FILE* file);

	AudioFormat			_format;
	AudioCompression	_compression;
	uint32_t			_numChannels;
	uint32_t			_sampleRate;
	uint32_t			_byteRate;
	uint32_t			_blockAlign;
	uint32_t			_bitsPerSample;
	uint8_t*			_data;
	size_t				_data_size;
};
