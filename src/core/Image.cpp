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
	unsigned int imageSize;
	unsigned char* data;

	FILE* file = fopen(path.c_str(), "rb");
	if (!file)
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

	dataPos	= *(int*)&(header[0x0A]);
	_width	= *(int*)&(header[0x12]);
	_height	= *(int*)&(header[0x16]);

	imageSize = _width * _height * 3;
	if (dataPos == 0) dataPos = 54;

	data = new unsigned char[imageSize];
	fread(data, 1, imageSize, file);
	_pixels = new Pixel[_width * _height];

	for (int i = 0; i < _width * _height; i++)
	{
		int b = data[i * 3 + 0];
		int g = data[i * 3 + 1];
		int r = data[i * 3 + 2];
		_pixels[i] = 255 << 24 | r << 16 | g << 8 | b;
	}
	
	delete data;

	fclose(file);
}

}