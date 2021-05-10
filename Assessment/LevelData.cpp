#include "LevelData.h"

//Morgan

char LevelData::GetTile(int x, int y)
{
	return backgroundTiles[x][y];
}

std::string LevelData::GetLevelName()
{
	return LevelName;
}

void LevelData::Update()
{
	for (int i = 0; i < entityLoop.size(); i++)
	{
		entityLoop[i]->Update(EngineStatics::GetDeltaTime());
	}
}
