#include "Canvas.h"

namespace xy
{

uint32_t Canvas::_width = 0;
uint32_t Canvas::_height = 0;
Pixel* Canvas::_pixels = nullptr;
Color Canvas::_transparentColor = Color::magenta;

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

void Canvas::setTransparencyColor(const Color& color)
{
	_transparentColor = color;
}

void Canvas::clear(const Color& clearColor)
{
	const Pixel p = colorByteToPixel(clearColor);
	for (uint32_t i = 0; i < _width * _height; i++)
	{
		_pixels[i] = p;
	}
}

void Canvas::drawPixel(int x, int y, const Color& color)
{
	if (x < 0 || x >= (int)_width || y < 0 || y >= (int)_height)
		return;
	_pixels[x + y * _width] = colorByteToPixel(color);
}

void Canvas::drawRectangle(
	int x, 
	int y, 
	int width, 
	int height, 
	const Color& color)
{
	const Pixel p = colorByteToPixel(color);

	for (int ypix = y; ypix < y + height; ypix++)
	{
		if (ypix < 0) continue;
		if ((uint32_t)ypix >= _height) break;

		for (int xpix = x; xpix < x + width; xpix++)
		{
			if (xpix < 0) continue;
			if ((uint32_t)xpix >= _width) break;

			_pixels[xpix + ypix * _width] = p;
		}
	}
}

void Canvas::drawImage(int x, int y, Image* image)
{
	const uint32_t iw = image->getWidth();
	const uint32_t ih = image->getHeight();
	const Pixel tc = colorByteToPixel(_transparentColor);

	for (int iy = 0; iy < (int)ih; iy++)
	{
		int py = iy + y;
		if (py < 0) continue;
		if (py >= (int)_height) break;
		for (int ix = 0; ix < (int)iw; ix++)
		{
			int px = ix + x;
			if (px < 0) continue;
			if (px >= (int)_width) break;
			Pixel p = image->_pixels[ix + iy * iw];
			if (p == tc)
				continue;
			_pixels[px + py * _width] = p;
		}
	}
}

void Canvas::drawImagePortion(
	int x, 
	int y, 
	uint32_t imgx, 
	uint32_t imgy,
	uint32_t width,
	uint32_t height,
	Image* image)
{
	const int iw = image->getWidth();
	const int ih = image->getHeight();
	const Pixel tc = colorByteToPixel(_transparentColor);

	for (int ix = imgy; ix < (int)(imgy + height); ix++)
	{
		if (ix >= ih) continue;
		int yy = y + ix;
		if (yy < 0) continue;
		if ((uint32_t)yy >= _height) break;

		for (int iy = imgx; iy < (int)(imgx + width); iy++)
		{
			if (iy >= iw) continue;
			int xx = x + iy;
			if (xx < 0) continue;
			if ((uint32_t)xx >= _width) break;

			Pixel p = image->_pixels[iy + ix * iw];
			if (p == tc)
				continue;
			_pixels[xx + yy * _width] = p;
		}
	}
}

}