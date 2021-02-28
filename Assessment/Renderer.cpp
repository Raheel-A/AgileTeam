#include "Renderer.h"

SDL_Renderer* Renderer::renderer = nullptr;

Renderer::~Renderer()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

bool Renderer::CreateWindow(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
#pragma region Create Window

	window = nullptr;

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Check if SDL is inicialized
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		//create the window
		window = SDL_CreateWindow(
			title,				//title
			xpos,				//initial x position
			ypos,				//initial y position
			width,				//width, in pixels
			height,				//height, in pixels
			flags				//window behaviour flags (ignorw for now)
		);

		if (!window)
		{
			printf("WINDOW initialisation failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return false;
		}

		//Create Renderer
		renderer = SDL_CreateRenderer(
			window,				//link the renderer to our newly created win
			-1,					//index rendering driver (ignore for now)
			0					//renderer behaviour flags (ignore for now)
		);

		if (!renderer)
		{
			printf("RENDERER initialisation failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return false;
		}

		if (renderer)
		{
			SDL_SetRenderDrawColor(
				renderer,		//our target renderer
				255,			//r
				255,			//g
				255,			//b
				255				//alpha
			);
		}


		return true;
	}
	else
	{
		return false;
	}
#pragma endregion Create Window
}

void Renderer::GameDraw()
{


	//Draw on screen
	SDL_RenderPresent(renderer);

	//Clean window
	SDL_RenderClear(renderer);
}

void Renderer::UIDraw()
{
}
