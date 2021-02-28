#include "Renderer.h"

SDL_Renderer* Renderer::renderer = nullptr;

Renderer::~Renderer()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

/// <summary>
/// Create the window
/// </summary>
/// <param name="title"> - Use a string for the tile on the top of the window</param>
/// <param name="xpos"> - X position of the window on screen</param>
/// <param name="ypos"> - Y position of the window on screen</param>
/// <param name="width"> - With of the Window</param>
/// <param name="height"> - Height of the Window</param>
/// <param name="fullscreen"> - Bool to indicate if it is fullscreen</param>
/// <returns></returns>
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

/// <summary>
/// Use to show the in game frame
/// </summary>
void Renderer::GameDraw()
{


	//Draw on screen
	SDL_RenderPresent(renderer);

	//Clean window
	SDL_RenderClear(renderer);
}

/// <summary>
/// Use to show the UI
/// </summary>
void Renderer::UIDraw()
{

}
