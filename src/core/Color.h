#pragma once

#include <stdint.h>

namespace xy
{

typedef unsigned int Pixel;

struct Colorf;

// Color struct that uses 4 bytes to represent RGBA
// Range 0 - 255
struct Color
{
public:
	Color(
		unsigned char r,
		unsigned char g,
		unsigned char b,
		unsigned char a = 0);

	Color(const Colorf& other);

	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	static Color white;
	static Color black;
	static Color red;
	static Color green;
	static Color blue;
	static Color cyan;
	static Color magenta;
	static Color yellow;
};

// Color class that uses 4 floats to represent RGBA
// Range 0.0f - 1.0f
struct Colorf
{
	Colorf(float r, float g, float b, float a);

	float r;
	float g;
	float b;
	float a = 0.0f;
};

// Coverts from a Colorf to a Color
Color colorFloatToByte(const Colorf& in);

// Converts from a Color to a Colorf
Colorf colorByteToFloat(const Color& in);

// Converts from a Color to a Pixel
Pixel colorByteToPixel(const Color& in);

// Converts from a Pixel to a Color
Color colorPixelToByte(const Pixel& in);

}