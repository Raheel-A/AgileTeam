#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "Renderer.h"

#include "EngineStatics.h"
#include "Source/Player.h"
#include "Source/InputSystem/Input.h"

#undef main

using namespace std;

int main(void) 
{
	bool running = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "Could not initialise SDL, SDL Error:" << SDL_GetError() << endl;
		running = false;
	}
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		cout << "Could not initialise SDL_Image, SDL_Image Error:" << IMG_GetError() << endl;
		running = false;
	}
	if (TTF_Init())
	{
		cout << "Could not initialise SDL_TTF, SDL_TTF Error:" << TTF_GetError() << endl;
		running = false;
	}
	if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3)
	{
		cout << "Could not initialise SDL_Mixer, SDL_Mixer Error:" << Mix_GetError() << endl;
		running = false;
	}

	// Collision test
	Player* p1 = new Player(0, 0, 10, 10);
	Player* p2 = new Player(5, 5, 10, 10);

	if (p1->CheckCollision(p1, p2))
	{
		cout << "Collision occured" << endl;
	}
	else
	{
		cout << "No collision" << endl;
	}

	Renderer* a = new Renderer;
	a->CreateWindow("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	// Input test
	Input* i = new Input;
	bool quit = false;
	while (!quit && running)
	{
		i->Update();
		quit = i->KeyIsDown(KEY_ESC) ? true : false;

		//Check input and move accordingly 
		if (i->KeyIsDown(KEY_UP))
		{
			p1->Move(1);
		}

		if (i->KeyIsDown(KEY_LEFT))
		{
			p1->Move(2);
		}

		if (i->KeyIsDown(KEY_DOWN))
		{
			p1->Move(3);
		}

		if (i->KeyIsDown(KEY_RIGHT))
		{
			p1->Move(4);
		}

	}



	getchar();
	SDL_Quit();
}