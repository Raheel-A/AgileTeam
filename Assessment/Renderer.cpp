#pragma once
#include "Renderer.h"
#include "Source/Player.h"
#include "Sprite.h"
#include "LevelData.h"
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
	//Draw on screen
	SDL_RenderPresent(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 165, 253, 255);
	//Clean window
	SDL_RenderClear(renderer);
}

/// <summary>
/// Camera functioning with movement
/// </summary>
void Renderer::CameraFunctionality(float value, bool isHorizontal)
{
	//find the movement direction and then set the correct viewport from this
	if (isHorizontal)
	{
		setViewPortX(value);
	}
	else if (!isHorizontal)
	{
		setViewPortY(value);
	}
}

/// <summary>
/// Use to show the UI - will be used by UI team
/// </summary>
void Renderer::UIDraw(SDL_Rect dest, SDL_Texture* text)
{
	SDL_RenderCopy(renderer, text, NULL, &dest);
}

/// <summary>
/// Use to draw a tile in the level - CW
/// </summary>
void Renderer::DrawTile(Sprite* sprite, int w, int h)
{
	//get the sprites position and stores it in a vector2
	positionHolder = sprite->getPos();

	//set height and width to what is inputted due to different sprites being different sizes
	destinationRect.h = h;
	destinationRect.w = w;
	//set x & y based on the sprites position
	destinationRect.x = positionHolder.x;
	destinationRect.y = positionHolder.y;

	//draw the sprite object at the newly created destination rect
	SDL_RenderCopy(renderer, sprite->GetSprite(), NULL, &destinationRect);
}

/// <summary>
/// Use to draw the level based on the level vector - CW
/// THIS WILL TAKE IN THE ARRAY FROM LEVEL LOADING - USING PLACEHOLDER VECTOR FOR NOW
/// </summary>
void Renderer::DrawCurrentLevel(LevelData* level, Player* player)
{
	viewportX = player->GetX() - (SCREENWIDTH/2);
	viewportY = player->GetY() - (SCREENHEIGHT/2);

	//Represents the min amount of rows and columns to cycle through, presumed to be 0
	int minimumValue = 0; 
	//these need to be seperate incase the level is not square, this is for max rows/columns that need to be cycled through
	int rowSizeMax = level->GetWidth(); 
	int columnSizeMax = level->GetHeight();
	vector<vector<char>> levelTiles = level->GetLevelTiles();
	
	//cycle through vector to assign each tile
	for (int row = minimumValue; row < rowSizeMax; row++)
	{
		for (int column = minimumValue; column < columnSizeMax; column++)
		{
			//the current tile is where the vector is at in x & y positions
			char currentTile = levelTiles[row][column];
			//create a vector to hold the current position in - blockSize is for how far apart the tiles are placed 
			//(so column 3 will actually be at xpos 96 for eg; this is to account for block size/placement)
			Vector2 pos = { column * blockSize, row * blockSize };

			//cycle through the tile at designated pos
			//switch (currentTile)
			//{
			//case GRASS:
			//{
			//	//This draws a texture from a preloaded list and uses the enum from earlier to find the correct texture, it then draws it at the 
			//	// position (row*32), (column *32) and applies width and height

			//	//Set pos of sprite (based on enum, 0 is placeholder)
			//	spriteList[0]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));

			//	//Draw tile, 0 is placeholder it will represent an enum for the desired tile
			//	//blockSize could be substituted with different ints to change the size of the tile
			//	DrawTile(spriteList[0], blockSize, blockSize);
			//}
			//break;
			//case WALL:
			//{
			//	spriteList[1]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
			//	DrawTile(spriteList[1], blockSize, blockSize);
			//}
			//break;
			//default:
			//	break;
			//}

			switch (currentTile)
			{
			case PATH:
				spriteList[0]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[0], blockSize, blockSize);
				break;
			case MOUNTAIN:
				spriteList[1]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[1], blockSize, blockSize);
				break;
			case GRASS:
				spriteList[2]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[2], blockSize, blockSize);
				break;
			case TREES:
				spriteList[3]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[3], blockSize, blockSize);
				break;
			case WALL:
				spriteList[4]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[4], blockSize, blockSize);
				break;
			case FLOOR:
				spriteList[5]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[5], blockSize, blockSize);
				break;
			case PIT:
				spriteList[6]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[6], blockSize, blockSize);
				break;
			/*case DOOR:
				spriteList[7]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[7], blockSize, blockSize);
				break;
			case FENCE:
				spriteList[8]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[8], blockSize, blockSize);
				break;
			case POT:
				spriteList[9]->setPos(Vector2(pos) - Vector2(viewportX, viewportY));
				DrawTile(spriteList[9], blockSize, blockSize);
				break;*/
			default:
				break;
			}

		}
	}
}

void Renderer::setViewPortX(float viewportx)
{
	// with these you would then do setViewPortX(m_pot_x_pos - m_x_pos); when you move the character,in input perhaps, update the potential position //

	if (viewportX + viewportx < 0)
	{
		viewportX = 0;
	}
	else
	{
		viewportX = viewportx;
	}

	viewport.x = viewportX;
	SDL_RenderSetViewport(renderer, &viewport);
}

void Renderer::setViewPortY(float viewporty)
{
	viewportY = viewporty;

	viewport.y = viewportY;
	SDL_RenderSetViewport(renderer, &viewport);
}
