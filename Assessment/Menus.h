#pragma once
#include "SDL.h"
#include <vector>
#include "Text.h"
#include "ImageLoader.h"
#include "Renderer.h"
#include "HUD.h"

enum MenuState { Start, Paused, InGame };

enum StartScreenSelected { Play, Quit };

class Menus
{
public:
	Menus(Renderer* r);
	~Menus();
	
	void ChangeMenu(MenuState newMenu);
	void PrintSelection() { std::cout << selected; }
	void DisplayMenu();

	void ChangeStartSelection(StartScreenSelected newSelected);
	void SelectButton(bool& fuckthisshit);
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
	StartScreenSelected selected;
	const string arrowPath = "Assets/swordpointer.bmp";
	SDL_Rect pointerRect;

	SDL_Rect pointerRectStart{ 470, 210, 58, 15};
	SDL_Rect pointerRectQuit{ 470, 260, 58, 15};
	SDL_Texture* StartBackground;

	void MoveSelectedPointer();

	const string StartBGPath = "Assets/StartImage.bmp";
	SDL_Texture* selectedArrow;

	Text* start_Title;
	Text* start_Start;
	Text* start_Settings;
	Text* start_Quit;
	vector<Text*> startMenuTexts;
	int startFontSize = 30;

	//HUD
	HUD* hud;
};

