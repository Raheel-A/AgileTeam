///Renderer

/* Change Log
28/02/2021 Mario - Creation of the renderer class and window
04/03/2021 Chase - Creating map drawing functionality
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
enum TILES
{
	BLOCK = 'A',
	WALL = 'B',
};

class Renderer
{
public:

	Renderer();
	~Renderer();

	static SDL_Renderer* renderer;

	bool CreateWindow(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void GameDraw();
	void UIDraw();
	//CW
	void DrawTile(Sprite* sprite, int w, int h);
	TILES tiles;
	vector<string> level = { "BBBBBBBBBB" ,
							 "BAAAAAAAAB",
						     "BAAAAAAAAB",
							 "BAAAAAAAAB",
							 "BAAAAAAAAB" ,
							 "BAAAAAAAAB" ,
							 "BAAAAAAAAB" ,
							 "BAAAAAAAAB" ,
							 "BAAAAAAAAB" ,
							 "BBBBBBBBBB" };
	void DrawLevel();
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
	
	Vector2 positionHolder;
};

