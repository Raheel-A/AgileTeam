#include "Renderer.h"
#include "Sprite.h"
#include "Source/InputSystem/Input.h"

SDL_Renderer* Renderer::renderer = nullptr;

Renderer::Renderer()
{

}

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
	//Camera 
	if (Input::KeyIsDown(KEY_RIGHT))
	{
		setViewPortX(1);
	}
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

/// <summary>
/// Use to draw a singular tile - CW
/// </summary>
void Renderer::DrawTile(Sprite* sprite, int w, int h)
{
	positionHolder = sprite->getPos();

	//perhaps h&w can be set in sprite class too?
	destinationRect.h = h;
	destinationRect.w = w;
	destinationRect.x = positionHolder.x;
	destinationRect.y = positionHolder.y;

	//draw assigned texture to renderer at desired location
	SDL_RenderCopy(renderer, sprite->GetSprite(), NULL, &destinationRect);

}

/// <summary>
/// Use to draw the level based on the level vector - CW
/// THIS WILL TAKE IN THE ARRAY FROM LEVEL LOADING
/// </summary>
void Renderer::DrawLevel()
{
	const int blockMultiplier = 32; //this will change based on size of sprites
	 //this relates to the enum from the level loading (e.g. x = grass tile) unsure whether we set this up?

	//THESE VARS ARE JUST TO FILL THE FUNCTION - THE REAL VALUES WILL COME FROM LEVEL LOADING
	//Represents the maximum amount of rows and columns to cycle through
	int rowMin = 0; 
	int rowMax = 10;
	int columnMin = 0;
	int columnMax = 10;
	
	//vector to go through each tile
	for (int row = rowMin; row < rowMax; row++)
	{
		for (int column = columnMin; column < columnMax; column++)
		{
			//Commented in until we get the level loading stuff
			tileToDraw = level[row][column];

			switch (tileToDraw)
			{
			case 'A':
			{
				//This draws a texture from a preloaded list and uses the enum from earlier to find the correct texture, it then draws it at the 
				// position (row*32), (column *32) and applies width and height

				//Set pos of sprite (based on enum, 0 is placeholder)
				/*spriteList[0]->setPos.x = (column * blockMultiplier);
				spriteList[0]->setPos.y = (row * blockMultiplier);*/
				Vector2 pos = { column * blockMultiplier, row * blockMultiplier };
				spriteList[0]->setPos(Vector2(pos));

				//Draw tile, 0 is placeholder it will represent an enum for the desired tile
				DrawTile(spriteList[0], blockMultiplier, blockMultiplier);
			}
			break;
			case 'B':
			{

				Vector2 pos = { column * blockMultiplier, row * blockMultiplier };
				spriteList[1]->setPos(Vector2(pos));

				//Draw tile, 0 is placeholder it will represent an enum for the desired tile
				DrawTile(spriteList[1], blockMultiplier, blockMultiplier);
			}
			break;
			default:
				break;
			}
		}
	}
}

void Renderer::setViewPortX(int viewportx)
{
	// with these you would then do setViewPortX(m_pot_x_pos - m_x_pos); when you move the character,in input perhaps, update the potential position //

	if (viewportX + viewportx < 0)
	{
		viewportX = 0;
	}
	else
	{
		viewportX += viewportx;
	}

	viewport.x = viewportX;
	SDL_RenderSetViewport(renderer, &viewport);
}

void Renderer::setViewPortY(int viewporty)
{
	viewportY += viewporty;

	viewport.y = viewportY;
	SDL_RenderSetViewport(renderer, &viewport);
}
