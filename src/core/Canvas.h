#pragma once

#include "Color.h"
#include "Image.h"

#include <stdint.h>

namespace xy
{

class Canvas
{
private:
	static void initialize(uint32_t width, uint32_t height);
	static void finalize();

	static uint32_t _width;
	static uint32_t _height;
	static Pixel* _pixels;
	static Color _transparentColor;

	friend class Core;

public:
	// TODO: Implement drawing methods
	// drawPixel
	// drawRectangle
	// drawCircle
	// ...

	static void setTransparencyColor(const Color& color);

	// Clears the screen using the specified color
	static void clear(const Color& clearColor);

	// Draw a pixel at 
	static void drawPixel(int x, int y, const Color& color);

	// Draws a rectangle at (x, y)
	static void drawRectangle(
		int x, 
		int y, 
		int width, 
		int height, 
		const Color& color);

	static void drawImage(int x, int y, Image* image);
};

}