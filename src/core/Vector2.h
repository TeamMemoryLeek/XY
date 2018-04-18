#pragma once

namespace xy
{

class Vector2
{
public:
	Vector2(const float& x = 0.f, const float& y = 0.f);
	Vector2(const Vector2& other);

	float x;
	float y;

	// Returns the length/magnitude of the vector
	float length() const;

	// Returns the squared length/magnitude of the vector
	float lengthSquared() const;

	// Normalizes the vector, and returns the length
	float normalize();

	// Returns a normalized version of this vector
	// Sets the value of outLength to the length of the vector
	const Vector2 normalized(float* outLength = nullptr) const;

	// Returns the dot product for this vector and another
	float dot(const Vector2& other) const;

	// Returns the dot product of two vectors
	static float dot(const Vector2& a, const Vector2& b);

	static const Vector2 zero;
	static const Vector2 up;
	static const Vector2 down;
	static const Vector2 left;
	static const Vector2 right;

	// Addition
	const Vector2 operator + (const Vector2& in) const;
	void operator += (const Vector2& in);

	// Subtraction
	const Vector2 operator - (const Vector2& in) const;
	const Vector2 operator - () const;
	void operator -= (const Vector2& in);

	// Scaling
	const Vector2 operator * (const float in) const;
	void operator *= (const float in);

	// Comparison
	bool operator == (const Vector2& in) const;
	bool operator != (const Vector2& in) const;
};

}
