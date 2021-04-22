#include <iostream>

#include "LevelNode.h"

LevelNode::LevelNode(bool isTraversible, Vector2Int position) :isTraversible(isTraversible), pos(position) {}

LevelNode::~LevelNode()
{
}

void LevelNode::ResetCostData()
{
	g = 0;
	h = 0;
	f = 0;
	parentNode = nullptr;
}

void LevelNode::PrintPos()
{
	std::cout << '(' << pos.x << ',' << pos.y << ')' << std::endl;
}
