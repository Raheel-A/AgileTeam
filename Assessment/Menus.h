#pragma once
#include "SDL.h"
#include <vector>
#include "Text.h"
#include "ImageLoader.h"
#include "Renderer.h"
#include "HUD.h"

enum MenuState { Start, Paused, InGame };

class Menus
{
public:
	Menus(Renderer* r);
	~Menus();
	
	void ChangeMenu(MenuState newMenu);
	void DisplayMenu();
private:
	Renderer* renderer;
	SDL_Renderer* sdl_rend;
	ImageLoader* imageLoader;

	MenuState menustate = MenuState::Start;

	void CreatePauseMenu();
	void CreateStartMenu();

	SDL_Rect backgroundRect{ 0,0, 800, 640 };

	//PAUSE MENU
	SDL_Texture* PauseBackground;
	const string PauseBGPath = "Assets/PauseImage.bmp";

	Text* pause_Title;
	Text* pause_Resume;
	Text* pause_Save;
	Text* pause_Load;
	Text* pause_Settings;
	Text* pause_Quit;
	vector<Text*> pauseMenuTexts;
	int pauseFontSize = 30;

	//START MENU
	SDL_Texture* StartBackground;
	const string StartBGPath = "Assets/StartImage.bmp";

	Text* start_Title;
	Text* start_Start;
	Text* start_Settings;
	Text* start_Quit;
	vector<Text*> startMenuTexts;
	int startFontSize = 30;

	//HUD
	HUD* hud;
};

