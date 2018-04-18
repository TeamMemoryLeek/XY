#include "Vector2.h"
#include <math.h>

namespace xy
{

const Vector2 Vector2::zero		= Vector2(0.f, 0.f);
const Vector2 Vector2::up		= Vector2(0.f, 1.f);
const Vector2 Vector2::down		= Vector2(0.f, -1.f);
const Vector2 Vector2::left		= Vector2(-1.f, 0.f);
const Vector2 Vector2::right	= Vector2(1.f, 0.f);

Vector2::Vector2(const float& x, const float& y)
	: x(x)
	, y(y)
{
}

Vector2::Vector2(const Vector2& other)
	: x(other.x)
	, y(other.y)
{
}

float Vector2::length() const 
{
	return (float)sqrt(lengthSquared());
}

float Vector2::lengthSquared() const
{
	return x * x + y * y;
}

float Vector2::normalize()
{
	float l = length();
	float f = 1.0f / l;
	if (l != 0.f) // TODO: Epsilon comparison
	{
		x *= f;
		y *= f;
	}
	return l;
}


const Vector2 Vector2::normalized(float* outLength /*= nullptr*/) const
{
	Vector2 r = *this;

	float l = r.normalize();
	if (outLength)
		*outLength = l;

	return r;
}

float Vector2::dot(const Vector2& other) const
{
	return x * other.x + y * other.y;
}

float Vector2::dot(const Vector2& a, const Vector2& b)
{
	return a.x * b.x + a.y + b.y;
}

const Vector2 Vector2::operator + (const Vector2& in) const
{
	return Vector2(x + in.x, y + in.y);
}

void Vector2::operator += (const Vector2& in)
{
	x += in.x;
	y += in.y;
}

const Vector2 Vector2::operator - (const Vector2& in) const
{
	return Vector2(x - in.x, y - in.y);
}

const Vector2 Vector2::operator - () const
{
	return Vector2(-x, -y);
}

void Vector2::operator -= (const Vector2& in)
{
	x -= in.x;
	y -= in.y;
}

const Vector2 Vector2::operator * (const float in) const
{
	return Vector2(x * in, y * in);
}

void Vector2::operator *= (const float in)
{
	x *= x;
	y *= y;
}

// TODO: Epsilon comparison
bool Vector2::operator == (const Vector2& in) const
{
	return x == in.x && y == in.y;
}

bool Vector2::operator != (const Vector2& in) const
{
	return x != in.x || y != in.y;
}

}