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
	delete _data;
}

void Image::loadFromFile(const std::string& path)
{
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int imageSize;

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

	_data = new unsigned char[imageSize];
	
	fread(_data, 1, imageSize, file);

	fclose(file);
}

}