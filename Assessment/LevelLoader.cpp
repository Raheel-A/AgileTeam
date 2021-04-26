#include "LevelLoader.h"

/// <summary>
/// Populates the LevelArray Vector
/// </summary>
void LevelLoader::PopulateLevelArray()
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
			if (line == levelHeader)
			{
				while (line != levelHeader_End && !infile.eof())
				{
					getline(infile, line);
					LevelArray.push_back(line);
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
