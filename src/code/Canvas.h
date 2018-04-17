#pragma once

namespace xy
{

typedef unsigned int Pixel;

class Canvas
{
public:
	Canvas(unsigned int width, unsigned int height);
	~Canvas();

	// TODO: Implement drawing methods
	// drawPixel
	// drawRectangle
	// drawCircle
	// ...

private:
	unsigned int _width;
	unsigned int _height;
	Pixel* _pixels;
};

}