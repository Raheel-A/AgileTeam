#pragma once
#include "SDL.h"
#include <vector>
#include "Text.h"
#include "ImageLoader.h"
#include "Renderer.h"
#include "HUD.h"

enum GameState { GAMESTATE_START, GAMESTATE_PAUSED, GAMESTATE_INGAME, GAMESTATE_QUIT };

enum StartScreenSelected { STARTSCREEN_PLAY, STARTSCREEN_QUIT };

enum PauseScreenSelected { PAUSE_RESUME, PAUSE_QUIT };

class Menus
{
public:
	Menus(Renderer* r);
	~Menus();
	
	void ChangeMenu(GameState newMenu);
	void PrintSelection() { std::cout << menustate << "\n"; }
	void DisplayMenu();

	void PauseGame(GameState& gameState);
	void UnpauseGame(GameState& gameState);

	void ChangeStartSelection(StartScreenSelected newSelected);
	void ChangePauseSelected(PauseScreenSelected newSelected);
	void SelectButton(GameState& gameState);
	//HUD
	HUD* hud;
private:
	Renderer* renderer;
	SDL_Renderer* sdl_rend;
	ImageLoader* imageLoader;

	GameState menustate = GameState::GAMESTATE_START;

	void CreatePauseMenu();
	void CreateStartMenu();

	SDL_Rect backgroundRect{ 0,0, 800, 640 };

	//PAUSE MENU
	PauseScreenSelected pauseSelected;
	
	SDL_Texture* pauseOverlay;
	const string pauseOverlayPath = "Assets/pauseOverlay.bmp";
	SDL_Rect pauseMenuPointerRect;
	SDL_Rect pausePointerRectPlay{ 290, 190, 58, 65 };
	SDL_Rect pausePointerRectQuit{ 290, 240, 58, 65 };

	Text* pause_Title;
	Text* pause_Resume;
	Text* pause_Quit;
	vector<Text*> pauseMenuTexts;
	int pauseFontSize = 30;

	//START MENU
	StartScreenSelected selected;
	const string arrowPath = "Assets/sebface.bmp";//"Assets/swordpointer.bmp";

	SDL_Rect startMenuPointerRect;
	SDL_Rect pointerRectStart{ 190, 190, 58, 65};
	SDL_Rect pointerRectQuit{ 190, 240, 58, 65};
	SDL_Texture* StartBackground;

	void MoveSelectedPointer();

	const string StartBGPath = "Assets/jackolantern.bmp";
	SDL_Texture* selectedArrow;

	Text* start_Title;
	Text* start_Start;
	Text* start_Settings;
	Text* start_Quit;
	vector<Text*> startMenuTexts;
	int startFontSize = 30;

};

