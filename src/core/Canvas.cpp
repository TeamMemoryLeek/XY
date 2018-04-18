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
	for (int ypix = y; ypix < y + height; ypix++)
	{
		if (ypix < 0) continue;
		if ((uint32_t)ypix >= _height) break;

		for (int xpix = x; xpix < x + width; xpix++)
		{
			if (xpix < 0) continue;
			if ((uint32_t)xpix >= _width) break;

			_pixels[xpix + ypix * _width] = colorByteToPixel(color);
		}
	}
}

}