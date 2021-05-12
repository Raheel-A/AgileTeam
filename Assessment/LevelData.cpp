#include "LevelData.h"
#include "Source/Entity.h"

LevelData::LevelData(std::string name, int width, int height, std::vector<std::vector<char>> tiles)
{
	LevelName = name;
	levelWidth = width;
	levelHeight = height;
	backgroundTiles = tiles;
}

LevelData::~LevelData()
{
}

char LevelData::GetTile(int x, int y)
{
	return backgroundTiles[x][y];
}

char LevelData::GetTile(Vector2 vector2)
{
	return backgroundTiles[vector2.x][vector2.y];
}

std::string LevelData::GetLevelName()
{
	return LevelName;
}

int LevelData::GetWidth()
{
	return levelWidth;
}

int LevelData::GetHeight()
{
	return levelHeight;
}

std::vector<std::vector<char>> LevelData::GetLevelTiles()
{
	return backgroundTiles;
}

void LevelData::Update()
{
	for (int i = 0; i < entityLoop.size(); i++)
	{
		entityLoop[i]->Update(EngineStatics::GetDeltaTime());
	}
}

std::vector<Entity*> LevelData::GetEntities()
{
	return entityLoop;
}
