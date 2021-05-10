#include "Menus.h"

Menus::Menus(Renderer* r)
{
	selected = StartScreenSelected::Play;
	pointerRect = pointerRectStart;

	renderer = r;
	sdl_rend = r->renderer;

	hud = new HUD(r);
	imageLoader = new ImageLoader(sdl_rend);
	CreatePauseMenu();
	CreateStartMenu();
}

Menus::~Menus()
{
}

void Menus::ChangeMenu(MenuState newMenu)
{
	menustate = newMenu;
}

void Menus::ChangeStartSelection(StartScreenSelected newSelected)
{
	selected = newSelected;
	MoveSelectedPointer();
}

void Menus::SelectButton(bool& fuckthisshit)
{
	switch (selected)
	{
	case StartScreenSelected::Play:
		std::cout << "\nPLAY\n";

		menustate = MenuState::InGame;
		break;
	case StartScreenSelected::Quit:
		fuckthisshit = true;
		break;
	default:
		break;
	}
}

void Menus::CreatePauseMenu()
{
	imageLoader->LoadeImage(PauseBGPath);
	PauseBackground = imageLoader->GetImage();

	//Title
	pause_Title = new Text(sdl_rend, pauseFontSize * 2, "PAUSED", 300, 0);
	pauseMenuTexts.push_back(pause_Title);
	//Resume
	pause_Resume = new Text(sdl_rend, pauseFontSize, "Resume", 350, 200);
	pauseMenuTexts.push_back(pause_Resume);
	//Save
	pause_Save = new Text(sdl_rend, pauseFontSize, "Save", 350, 250);
	pauseMenuTexts.push_back(pause_Save);
	//Load
	pause_Load = new Text(sdl_rend, pauseFontSize, "Load", 350, 300);
	pauseMenuTexts.push_back(pause_Load);
	//Settings
	pause_Settings = new Text(sdl_rend, pauseFontSize, "Settings", 350, 350);
	pauseMenuTexts.push_back(pause_Settings);
	//Quit
	pause_Quit = new Text(sdl_rend, pauseFontSize, "Quit", 350, 400);
	pauseMenuTexts.push_back(pause_Quit);
}

void Menus::CreateStartMenu()
{
	//BG
	imageLoader->LoadeImage(StartBGPath);
	StartBackground = imageLoader->GetImage();

	//Arrow
	imageLoader->LoadeImage(arrowPath);
	selectedArrow = imageLoader->GetImage();

	//Title
	start_Title = new Text(sdl_rend, pauseFontSize * 2, "TITLE", 300, 0);
	startMenuTexts.push_back(start_Title);

	//Start
	start_Start = new Text(sdl_rend, pauseFontSize, "Start Game",280, 200);
	startMenuTexts.push_back(start_Start);

	//Quit
	start_Quit = new Text(sdl_rend, pauseFontSize, "Quit", 310, 250);
	startMenuTexts.push_back(start_Quit);
}

void Menus::MoveSelectedPointer()
{
	switch (selected)
	{
	case Play:
		pointerRect = pointerRectStart;
		break;
	case Quit:
		pointerRect = pointerRectQuit;
		break;
	default:
		break;
	}
}

void Menus::DisplayMenu()
{
	switch (menustate)
	{
	case Start:
		renderer->UIDraw(backgroundRect, StartBackground);
		renderer->UIDraw(pointerRect, selectedArrow);
		for (int i = 0; i < startMenuTexts.size(); i++)
		{
			renderer->UIDraw(startMenuTexts[i]->textRect, startMenuTexts[i]->GetTexture());
		}
		break;

	case Paused:
		renderer->UIDraw(backgroundRect, PauseBackground);

		for (int i = 0; i < pauseMenuTexts.size(); i++)
		{
			renderer->UIDraw(pauseMenuTexts[i]->textRect, pauseMenuTexts[i]->GetTexture());
		}
		break;

	case InGame:
		hud->DisplayHUD();
		break;

	default:
		break;
	}
}
