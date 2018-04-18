#pragma once

#include "Color.h"

#include <string>

namespace xy
{

class Image
{
public:
	uint32_t getWidth() const { return _width; }
	uint32_t getHeight() const { return _height; }

	// TODO: setPixel and getPixel

private:
	Image();
	~Image();
	
	void loadFromFile(const std::string& path);
	Pixel* _pixels;

	uint32_t _width;
	uint32_t _height;
	unsigned char* _data;

	friend class Canvas;
	friend class Core;
};

}