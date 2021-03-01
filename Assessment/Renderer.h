///Renderer

/* Change Log
28/02/2021 Mario - Creation of the renderer class and window
*/

#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>

#include "SDL.h"

using namespace std;

class Renderer
{
public:

	~Renderer();

	static SDL_Renderer* renderer;

	bool CreateWindow(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void GameDraw();
	void UIDraw();

protected:

	SDL_Window* window;
};

