#include "Image.h"

#include <assert.h>

namespace xy
{

Image::Image()
{
}

Image::~Image()
{
	// TODO: Deallocate
	delete _pixels;
}

void Image::loadFromFile(const std::string& path)
{
	unsigned char header[54];
	unsigned int dataPos;
	unsigned long imageSize;
	unsigned char* data;

	FILE* file;
	if (fopen_s(&file, path.c_str(), "rb") != 0)
	{
		assert(false);
		// TODO: Error
	}

	if (fread(header, 1, 54, file) != 54)
	{
		assert(false);
	}

	if (header[0] != 'B' || header[1] != 'M')
	{
		assert(false);
	}

	dataPos		= *((int*)&header[0x0A]);
	imageSize	= *((int*)&header[0x22]);
	_width		= *((int*)&header[0x12]);
	_height		= *((int*)&header[0x16]);

	if (imageSize == 0) imageSize = _width * _height * 3;
	if (dataPos == 0) dataPos = 54;

	data = new unsigned char[imageSize];
	fread(data, 1, imageSize, file);
	_pixels = new Pixel[_width * _height];

	long i = 0;
	// Iterate rows backwards since bitmaps are stored that way
	for (int y = (int)_height - 1; y >= 0; y--)
	{
		for (int x = 0; x < (int)_width; x++)
		{
			uint8_t b = data[i + 0];
			uint8_t g = data[i + 1];
			uint8_t r = data[i + 2];
			_pixels[x + y * _width] = 255 << 24 | r << 16 | g << 8 | b;
			i += 3;
		}
		int pad = 0;
		if((_width * 3) % 4 != 0)
			pad = 4 - ((_width * 3) % 4);
		i += pad; // Apply row pad
	}

	delete data;

	fclose(file);
}

}