#pragma once

//Morgan

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Vector2.h"
using namespace std;

class LevelLoader
{
public:
	LevelLoader();
	~LevelLoader();

	vector <string> LevelArray;
	vector<Vector2> EnemyCoordinates;
	vector<Vector2> DungeonEntrenceCoordinates;
	vector<Vector2> Coordinates;


private:

	void PopulateLevelArray();
	vector <string> GetLevelArray();

	void PopulateEnemyCoordinates();

	string levelHeader = "<Level>";
	string levelHeader_End = "</Level>";

	string EnemyHeader = "<Enemies>";
	string EnemyHeader_End = "</Enemies>";

	string ItemHeader = "<Items>";
	string ItemHeader_End = "</Items>";

	string DungeonHeader = "<Dungeons>";
	string DungeonHeader_End = "</Dungeons>";

	char ValueSeperator = '/';
	char NextValue = ',';
	char EndOfValues = '.';
	char valueSpacer = ' ';
};