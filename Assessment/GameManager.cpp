#include "LevelData.h"
#include "Pathfinder.h"
#include "GameManager.h"
#include "Renderer.h"


void GameManager::UpdatePathfinder()
{
	// Initialise pathfinder
	pathfinder->m_canTraverseDiagonally = true;

	for (int y = 0; y < level->GetHeight() - 1; y++)
	{
		for (int x = 0; x < level->GetWidth() - 1; x++)
		{
			char tile = level->GetTile(x, y);
			bool isTraversible = !(
				TILES::MOUNTAIN == tile ||
				TILES::DOOR == tile ||
				TILES::FENCE == tile ||
				TILES::PIT == tile ||
				TILES::POT == tile ||
				TILES::TREES == tile ||
				TILES::WALL == tile);
			pathfinder->SetNodeIsTraversible(Vector2{ x,y }, isTraversible);
		}
	}
}
