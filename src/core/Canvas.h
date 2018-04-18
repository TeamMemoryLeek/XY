#pragma once

#include "Color.h"

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

	friend class Core;

public:
	// TODO: Implement drawing methods
	// drawPixel
	// drawRectangle
	// drawCircle
	// ...

	// Clears the screen using the specified color
	static void clear(Color clearColor);

	// Draw a pixel at 
	static void drawPixel(int x, int y, Color color);

	// Draws a rectangle at (x, y)
	static void drawRectangle(int x, int y, int width, int height, Color color);
};

}