#include "Canvas.h"

namespace xy
{

Canvas::Canvas(unsigned int width, unsigned int height)
	: _width(width)
	, _height(height)
{
	_pixels = new Pixel[width * height];
}

Canvas::~Canvas()
{
	delete _pixels;
}

}