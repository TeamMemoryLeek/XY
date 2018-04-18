#include "Color.h"

namespace xy
{

Color Color::white		= Color(255, 255, 255, 255);
Color Color::black		= Color(0,     0,   0, 255);
Color Color::red		= Color(255,   0,   0, 255);
Color Color::green		= Color(0,   255,   0, 255);
Color Color::blue		= Color(0,     0, 255, 255);
Color Color::cyan		= Color(0,   255, 255, 255);
Color Color::magenta	= Color(255,   0, 255, 255);
Color Color::yellow		= Color(255, 255,   0, 255);

Color::Color(
	unsigned char r, 
	unsigned char g, 
	unsigned char b, 
	unsigned char a)
	: r(r)
	, g(g)
	, b(b)
	, a(a)
{
}

Colorf::Colorf(float r, float g, float b, float a)
	: r(r)
	, g(g)
	, b(b)
	, a(a)
{
}

xy::Color colorFloatToByte(const Colorf& in)
{
	return Color(
		(unsigned char)(in.r * 255.0f),
		(unsigned char)(in.g * 255.0f),
		(unsigned char)(in.b * 255.0f),
		(unsigned char)(in.a * 255.0f));
}

xy::Colorf colorByteToFloat(const Color& in)
{
	return Colorf(
		(float)in.r / 255.0f,
		(float)in.g / 255.0f,
		(float)in.b / 255.0f,
		(float)in.a / 255.0f);
}

Pixel colorByteToPixel(const Color& in)
{
	return in.a << 24 | in.r << 16 | in.g << 8 | in.b;
}

Color colorPixelToByte(const Pixel& in)
{
	return Color(
		in & 255,
		(in >> 16) & 255,
		(in >> 8) & 255,
		(in >> 24) & 255);
}

}