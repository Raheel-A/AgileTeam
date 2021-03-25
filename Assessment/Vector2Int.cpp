#include "Vector2Int.h"

Vector2Int::Vector2Int() {}

Vector2Int::Vector2Int(int x, int y) : x(x), y(y) {}

Vector2Int::Vector2Int(Vector2 v) : x(v.x), y(v.y) {}

Vector2Int::~Vector2Int()
{
}
