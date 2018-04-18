#include "Canvas.h"

namespace xy
{

uint32_t Canvas::_width = 0;
uint32_t Canvas::_height = 0;
Pixel* Canvas::_pixels = nullptr;

void Canvas::initialize(uint32_t width, uint32_t height)
{
	_width = width;
	_height = height;
	_pixels = new Pixel[width * height];;
}

void Canvas::finalize()
{
	delete _pixels;
}

void Canvas::drawRectangle(int x, int y, int width, int height, Color color)
{
	for (uint32_t ypix = y; ypix < _height; ypix++)
	{
		if (ypix < 0) continue;
		if (ypix >= _height) break;

		for (uint32_t xpix = x; xpix < _width; xpix++)
		{
			if (xpix < 0) continue;
			if (xpix >= _width) break;

			// TODO: Fix color format
			_pixels[xpix + ypix * _width] = colorByteToPixel(color);
		}
	}
}

}