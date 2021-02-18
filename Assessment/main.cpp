#include "SDL.h"
#undef main

void main(void) 
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Quit();
}