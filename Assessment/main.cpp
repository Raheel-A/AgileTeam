#include <iostream>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "Renderer.h"
#include "Pathfinder.h"
#include "Vector2.h"

#include "EngineStatics.h"
#include "Source/Player.h"
#include "Source/InputSystem/Input.h"
#include "HUD.h"
#include "SoundManager.h"
#include "Menus.h"

#include "ImageLoader.h"
#include "Sprite.h"

#undef main

using namespace std;

void PathfinderTest()
{
	// Initialise pathfinder
	int levelWidth = 20, levelHeight = 10;
	Pathfinder p{ levelWidth,levelHeight };
	p.m_canTraverseDiagonally = false;
	// Create a wall (for testing)
	for (size_t i = 0; i < levelWidth - 1; i++)
		p.SetNodeIsTraversible(Vector2{ (float)i, 2.5f }, false);

	// Search for path
	vector<Vector2> path = p.FindPath({ 0.5f, 0.5f }, { 1.5f, 9.3f });
	p.PrintNodeMatrix(path);

	// Output path coordinates list
	/*for (size_t i = 0; i < path.size(); i++)
		cout << '(' << path[i].x << ',' << path[i].y << '), ';*/
	cout << endl;
}

void CollisionTest()
{
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
}


int main() 
{
	bool running = true;
	GameState gState = GameState::GAMESTATE_START;

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

	Renderer* renderer = new Renderer;
	renderer->CreateWindow("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	// Input test
	Input* i = new Input;

	Menus* UI = new Menus(renderer);

	SoundManager* sManager = new SoundManager();
	sManager->LoadMusic("Assets/music.wav");
	sManager->LoadSFXs(SFXList::Shoot, "Assets/shoot.wav");
	//sManager->PlayBGM(-1); //SHUSH

	bool quit = false;

	//Create a new image loader
	ImageLoader* imageloader = new ImageLoader(renderer->renderer);

	//Load sprites into the sprite-list for level loading
	renderer->spriteList.push_back(new Sprite(imageloader->LoadeImage("Assets/floorSprite.bmp")));
	renderer->spriteList.push_back(new Sprite(imageloader->LoadeImage("Assets/wallSprite.bmp")));

	//Create a seperate sprite for the player/enemy
	//Sprite* animExample = new Sprite(imageloader->LoadeImage("Assets/pumpkin_dude.bmp"), true);

	bool _isMenu = true;


	// Create a player and an enemy with a sprite
	Player* player = new Player(32, 32, 10, 10);
	player->LoadSprite(imageloader);

	Enemy* enemy = new Enemy(160, 160, 10, 10);
	enemy->LoadSprite(imageloader);
	
	vector<Entity*> entities;
	entities.push_back(player);
	entities.push_back(enemy);

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	//main loop
	while (gState != GameState::GAMESTATE_QUIT)
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

		i->UpdateInstance();

		quit = i->KeyIsDown(KEY_ESC);
		

		if (gState == GameState::GAMESTATE_START)
		{
			//Check input and move accordingly 
			//Rendering team addition: Take the keypress and move the camera accordingly (up, move the camera up the screen for example)
			if (i->KeyIsDown(KEY_UP))
			{
				UI->ChangeStartSelection(StartScreenSelected::STARTSCREEN_PLAY);
			}

			if (i->KeyIsDown(KEY_DOWN))
			{
				UI->ChangeStartSelection(StartScreenSelected::STARTSCREEN_QUIT);
			}

			if (i->KeyIsDown(KEY_RIGHT))
			{
				UI->ChangeMenu(GameState::GAMESTATE_START);
			}

			if (i->KeyIsDown(KEY_ENTER))
			{
				UI->SelectButton(gState);
			}
		}
		else if (gState == GameState::GAMESTATE_INGAME)
		{
			renderer->DrawCurrentLevel();

			// Update all entities
			for (int i = 0; i < entities.size(); i++)
			{
				entities[i]->Update(deltaTime);
			}

			//Draw the level, draw the animations and update them, then render everything else
			//renderer->DrawCurrentLevel();

			// Draw all entities
			for (int i = 0; i < entities.size(); i++)
			{
				entities[i]->Draw();
			}

			if (i->KeyIsDown(KEY_LEFT))
			{
				UI->hud->ChangeHealth(-1);
				UI->hud->ChangeGold(-5);
			}

			if (i->KeyIsDown(KEY_RIGHT))
			{
				UI->hud->ChangeHealth(1);
				UI->hud->ChangeGold(5);
			}

			if (i->KeyIsDown(KEY_SPACE))
			{
				UI->PauseGame(gState);
			}
		}
		else if (gState == GameState::GAMESTATE_PAUSED)
		{
			renderer->DrawCurrentLevel();

			// Draw all entities
			for (int i = 0; i < entities.size(); i++)
			{
				entities[i]->Draw();
			}

			if (i->KeyIsDown(KEY_UP))
			{
				UI->ChangePauseSelected(PauseScreenSelected::PAUSE_RESUME);
			}

			if (i->KeyIsDown(KEY_DOWN))
			{
				UI->ChangePauseSelected(PauseScreenSelected::PAUSE_QUIT);
			}

			if (i->KeyIsDown(KEY_ENTER))
			{
				UI->SelectButton(gState);
			}
		}

		UI->DisplayMenu();
		renderer->GameDraw();
	}
	
	SDL_Quit();
	return 0;
}
