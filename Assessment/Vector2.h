#pragma once

struct Vector2
{
	Vector2();
	Vector2(int x, int y);
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator+ (const Vector2& rhs);
	Vector2 operator- (const Vector2& rhs);
	Vector2 operator* (const float scalar);

	Vector2 Normalised();
	float Distance(Vector2 to);
	float Magnitude();

	float x = 0.0f, y = 0.0f;
};

