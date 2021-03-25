#pragma once
#include "Vector2.h"

struct Vector2Int
{
	Vector2Int();
	Vector2Int(int x, int y);
	Vector2Int(Vector2 v);
	~Vector2Int();

	int x = 0, y = 0;
};

