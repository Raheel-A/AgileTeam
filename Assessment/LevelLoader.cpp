#include "LevelLoader.h"

//Morgan

LevelData LevelLoader::LoadLevel(string levelName)
{
	this->levelName = levelName + ".txt";
	PopulateLevelArray();
	
	vector<vector<char>> tiles;

	for (int y = 0; y < LevelArray.size(); y++)
	{
		vector<char> currentRow;
		for (int x = 0; x < LevelArray[0].size(); x++)
		{
			currentRow.push_back(LevelArray[y][x]);
		}
		tiles.push_back(currentRow);
	}

	LevelData levelData{levelName, (int)LevelArray.size(), (int)LevelArray[0].size(), tiles};
	return levelData;
}

/// <summary>
/// Populates the LevelArray Vector
/// </summary>
void LevelLoader::PopulateLevelArray()
{
	//temp string
	string line;

	//load file
	ifstream infile(levelName);

	//check if file open
	if (infile.is_open())
	{
		do
		{
			getline(infile, line);
			if (line == LevelHeader)
			{
				while (line != LevelHeader_End && !infile.eof())
				{
					getline(infile, line);
					if (line != LevelHeader_End)
					{
						LevelArray.push_back(line);
					}
				}
			}
		} while (!infile.eof());
	}
	else
	{
		cout << "error opening file for input" << '\n';
		getchar();
		exit(1);
	}
}

vector<string> LevelLoader::GetLevelArray()
{
	return LevelArray;
}

void LevelLoader::PopulateEnemyCoordinates()
{
	//temp string
	string line;

	//load file
	ifstream infile("Level.txt");

	//check if file open
	if (infile.is_open())
	{

		do
		{
			getline(infile, line);
			if (line == EnemyHeader)
			{
				getline(infile, line);
				while (line != EnemyHeader_End && !infile.eof())
				{
					int itr = 0;

					//check for end of values
					while(line[itr] != '.')
					{
						string firstNumber = NULL;
						string secondNumber = NULL;

						//get first value
						for(int i = itr; line[i] != ValueSeperator; i++)
						{
							firstNumber.push_back(line[i]);
							itr++;
						}
						//get second value
						for (int i = itr; line[i] != NextValue && line[i] != EndOfValues; i++)
						{
							secondNumber.push_back(line[i]);
							itr++;
						}

						//skip space
						if (line[itr] == valueSpacer)
						{
							itr++;
						}

						Vector2 coordinate(stoi(firstNumber), stoi(secondNumber));
						EnemyCoordinates.push_back(coordinate);
					}

				}
			}
		} while (!infile.eof());
	}
	else
	{
		cout << "error opening file for input" << '\n';
		getchar();
		exit(1);
	}
}
