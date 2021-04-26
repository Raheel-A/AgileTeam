#pragma once
#include <string>
#include <vector>
#include "Source/Entity.h"
#include "EngineStatics.h"

class LevelData
{
public:
	LevelData();
	~LevelData();

private:
	std::vector<std::vector<char>> backgroundTiles;

	std::vector<Entity*> entityLoop;

	std::string LevelName = "Sample Text";
public:

	/// <summary>
	/// Gets a pointer to the background tiles vector.
	/// Maybe use GetTile instead for safety?
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

	/// <summary>
	/// Gets Name Of Level
	/// </summary>
	/// <returns> Name as String </returns>
	std::string GetLevelName();


	void Update();

};

