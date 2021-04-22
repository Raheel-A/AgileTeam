#pragma once
#include "Vector2Int.h"

struct LevelNode
{
public:
	LevelNode(bool isTraversible, Vector2Int position);
	~LevelNode();

	void ResetCostData();
	void PrintPos();

	LevelNode* parentNode = nullptr;
	float g = 0, h = 0, f = 0;
	bool isTraversible = true;
	Vector2Int pos;
};

