#include "Vector2.h"

Vector2::Vector2() {}
Vector2::Vector2(int x, int y) : x((float)x), y((float)y) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
Vector2::~Vector2() {}

Vector2 Vector2::operator+(const Vector2& rhs)
{
	return Vector2(x + rhs.x, y + rhs.y);
}