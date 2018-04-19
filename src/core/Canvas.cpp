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
	const int width = image->getWidth();
	const int height = image->getHeight();

	for (int ypix = 0; ypix < height; ypix++)
	{
		int yy = y + ypix;
		if (yy < 0) continue;
		if ((uint32_t)yy >= _height) break;

		for (int xpix = 0; xpix < width; xpix++)
		{
			int xx = x + xpix;
			if (xx < 0) continue;
			if ((uint32_t)xx >= _width) break;

			Pixel p = image->_pixels[xpix + ypix * width];
			if (p == colorByteToPixel(_transparentColor))
				continue;
			_pixels[xx + yy * _width] = p;
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

	for (int ypix = imgy; ypix < imgy + height; ypix++)
	{
		if (ypix >= ih) continue;
		int yy = y + ypix;
		if (yy < 0) continue;
		if ((uint32_t)yy >= _height) break;

		for (int xpix = imgx; xpix < imgx + width; xpix++)
		{
			if (xpix >= iw) continue;
			int xx = x + xpix;
			if (xx < 0) continue;
			if ((uint32_t)xx >= _width) break;

			Pixel p = image->_pixels[xpix + ypix * iw];
			if (p == colorByteToPixel(_transparentColor))
				continue;
			_pixels[xx + yy * _width] = p;
		}
	}
}

}