#pragma once
#include <vector>

#include "LevelNode.h"
#include "Vector2.h"
#include "Vector2Int.h"


class Pathfinder
{
public:
	Pathfinder(int width, int height);
	~Pathfinder();

	std::vector<Vector2> FindPath(Vector2 from, Vector2 to);
	void SetNodeIsTraversible(Vector2 nodePos, bool v);
	void SetNodeIsTraversible(Vector2Int nodePos, bool v);
	void PrintNodeMatrix(std::vector<Vector2> path = {});

	bool m_canTraverseDiagonally = false;

private:
	int GetIndex(int x, int y);
	LevelNode* IndexNodes(int x, int y);
	LevelNode* IndexNodes(Vector2Int v);
	Vector2Int GetReveseIndex(int i);
	bool IsInBounds(Vector2Int v);
	std::vector<LevelNode*>& AddNodeToPath(LevelNode* n, std::vector<LevelNode*>& path);

	int m_width, m_height;
	LevelNode** m_nodes = nullptr;

};

