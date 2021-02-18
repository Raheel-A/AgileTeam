#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#undef main

using namespace std;

void main(void) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		cout << "Could not initialise SDL, SDL Error:" << SDL_GetError() << endl;
	}
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		cout << "Could not initialise SDL_Image, SDL_Image Error:" << IMG_GetError() << endl;
	}
	if (TTF_Init())
	{
		cout << "Could not initialise SDL_TTF, SDL_TTF Error:" << TTF_GetError() << endl;
	}
	if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3)
	{
		cout << "Could not initialise SDL_Mixer, SDL_Mixer Error:" << Mix_GetError() << endl;
	}

	SDL_Quit();
}