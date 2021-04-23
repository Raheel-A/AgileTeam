#pragma once
#include <string>
#include <vector>
#include "Source/Entity.h"

class LevelData
{
public:
	LevelData();
	~LevelData();

private:
	std::vector<std::vector<char>> backgroundTiles;

	std::vector<Entity*> entityLoop;
public:

	/// <summary>
	/// Gets a pointer to the background tiles vector.
	/// Probably use GetTile instead?
	/// </summary>
	/// <returns>Pointer to background tiles vector</returns>
	std::vector<std::string>* GetBackgroundTilesPtr;

	/// <summary>
	/// Gets tile value from background tile vector.
	/// </summary>
	/// <param name="x"> Tile's X Position </param>
	/// <param name="y"> Tile's Y Position </param>
	/// <returns> tile as char </returns>
	char GetTile(int x, int y);

	void Update();

};

