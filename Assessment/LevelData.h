#pragma once
#include <string>
#include <vector>
//#include "Source/Entity.h"
#include "EngineStatics.h"
#include "Vector2.h"

class Entity;

struct LevelData
{
public:
	LevelData(std::string name, int width, int height, std::vector<std::vector<char>> tiles);
	~LevelData();

private:
	std::vector<std::vector<char>> backgroundTiles;

	std::vector<Entity*> entityLoop;

	std::string LevelName = "Sample Text";
	
	int levelWidth = 10;
	int levelHeight = 10;

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
	char GetTile(Vector2 vector2);

	/// <summary>
	/// Gets Name Of Level
	/// </summary>
	/// <returns> Name as String </returns>
	std::string GetLevelName();

	int GetWidth();
	int GetHeight();
	std::vector<std::vector<char>> GetLevelTiles();
	std::vector<Entity*> GetEntities();
	void AddEntity(Entity* e);

	void Update();

};

