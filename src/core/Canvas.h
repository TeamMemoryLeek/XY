#pragma once

#include "Color.h"

#include <stdint.h>

namespace xy
{

class Canvas
{
private:
	void initialize(uint32_t width, uint32_t height);
	void finalize();

	// TODO: Implement drawing methods
	// drawPixel
	// drawRectangle
	// drawCircle
	// ...

	static uint32_t _width;
	static uint32_t _height;
	static Pixel* _pixels;

	friend class Core;
};

}