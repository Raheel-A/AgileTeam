///Renderer

/* Change Log
28/02/2021 Mario - Creation of the renderer class and window
04/03/2021 Chase - Creating map drawing functionality
17/04/2021 Group 5 - Added assets and worked on game loop to ensure all of our functionality could be presented
18/04/2021 Chase - Commented the code we completed yesterday as a group
*/

#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "SDL.h"
#include <vector>
#include "Vector2.h"


using namespace std;
class Sprite;
class LevelData;
enum TILES
{
	/*GRASS = 'A',
	WALL = 'B',*/
	PATH = ' ',
	MOUNTAIN = 'h',
	GRASS = ':',
	TREES = 'M',
	DOOR = 'D',
	FENCE = 'F',
	WALL = 'W',
	FLOOR = 'f',
	PIT = 'b',
	POT = 'p',
	ENEMYSPAWN = 'e',
	BOSSSPAWN = 'E',
	PLAYERSPAWN = 'm',
};

class Renderer
{
public:

	Renderer();
	~Renderer();

	static SDL_Renderer* renderer;

	bool CreateWindow(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void GameDraw();
	void UIDraw(SDL_Rect dest, SDL_Texture* text);
	//CW
	void DrawTile(Sprite* sprite, int w, int h);
	TILES tiles;
	//placeholder vector as awaiting the level loading from other teams
	/*vector<string> level = { "BBBBBBBBBB" ,
							 "BAAAAAAAAB",
						     "BAAAAAAAAB",
							 "BAAAAAAAAB",
							 "BAAAAAAAAB" ,
							 "BAAAAAAAAB" ,
							 "BAAAAAAAAB" ,
							 "BAAAAAAAAB" ,
							 "BAAAAAAAAB" ,
							 "BBBBBBBBBB" };*/
	void DrawCurrentLevel(LevelData* data);
	vector <Sprite*> spriteList = {};
	//AP
	void CameraFunctionality( float value , bool isHorizontal);
	void setViewPortX(float viewportx);
	void setViewPortY(float viewporty);
	float viewportX = 0.0f;
	float viewportY = 0.0f;
protected:

	SDL_Window* window;
	//CW
	SDL_Rect viewport{0, 0, 1080, 1920};
	SDL_Rect destinationRect{ NULL };
	char tileToDraw = ' ';
	//stores the size of the tile based on level layout
	const int blockSize = 32;
	
	Vector2 positionHolder;
};

