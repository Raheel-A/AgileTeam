#include <math.h>
#include "Vector2.h"

Vector2::Vector2() {}
Vector2::Vector2(int x, int y) : x((float)x), y((float)y) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
Vector2::~Vector2() {}

Vector2 Vector2::operator+(const Vector2& rhs)
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const float scalar)
{
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::Normalised()
{
	float mag = sqrt(x * x + y * y);
	return Vector2(x / mag, y / mag);
}