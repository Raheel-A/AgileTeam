#include "Menus.h"

Menus::Menus(Renderer* r)
{
	selected = StartScreenSelected::STARTSCREEN_PLAY;
	pauseSelected = PauseScreenSelected::PAUSE_RESUME;

	startMenuPointerRect = pointerRectStart;
	pauseMenuPointerRect = pausePointerRectPlay;

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

void Menus::ChangeMenu(GameState newMenu)
{
	menustate = newMenu;
}

void Menus::ChangeStartSelection(StartScreenSelected newSelected)
{
	selected = newSelected;
	MoveSelectedPointer();
}

void Menus::ChangePauseSelected(PauseScreenSelected newSelected)
{
	pauseSelected = newSelected;
	MoveSelectedPointer();
}
void Menus::SelectButton(GameState& gameState)
{
	if (menustate == GameState::GAMESTATE_START)
	{
		switch (selected)
		{
		case StartScreenSelected::STARTSCREEN_PLAY:
			menustate = GameState::GAMESTATE_INGAME;
			break;
		case StartScreenSelected::STARTSCREEN_QUIT:
			menustate = GameState::GAMESTATE_QUIT;
			break;
		default:
			break;
		}
		gameState = menustate;
	}
	else if (menustate == GameState::GAMESTATE_PAUSED)
	{
		switch (pauseSelected)
		{
		case PAUSE_RESUME:
			menustate = GameState::GAMESTATE_INGAME;
			break;
		case PAUSE_QUIT:
			menustate = GameState::GAMESTATE_START;
			break;
		default:
			break;
		}
		gameState = menustate;
	}
}

void Menus::CreatePauseMenu()
{
	//overlay
	imageLoader->LoadeImage(pauseOverlayPath);
	pauseOverlay = imageLoader->GetImage();

	//Title
	pause_Title = new Text(sdl_rend, pauseFontSize * 2, "PAUSED", 300, 0);
	pauseMenuTexts.push_back(pause_Title);
	//Resume
	pause_Resume = new Text(sdl_rend, pauseFontSize, "Resume", 350, 200);
	pauseMenuTexts.push_back(pause_Resume);
	//Quit
	pause_Quit = new Text(sdl_rend, pauseFontSize, "Quit", 350, 250);
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
	start_Title = new Text(sdl_rend, pauseFontSize * 2, "Jack-o'-lantern 2", 100, 0);
	startMenuTexts.push_back(start_Title);

	//Start
	start_Start = new Text(sdl_rend, pauseFontSize, "Start Game", 0, 200);//280, 200);
	startMenuTexts.push_back(start_Start);

	//Quit
	start_Quit = new Text(sdl_rend, pauseFontSize, "Quit", 0, 250);//310, 250);
	startMenuTexts.push_back(start_Quit);
}

void Menus::MoveSelectedPointer()
{
	if (menustate == GameState::GAMESTATE_START)
	{
		switch (selected)
		{
		case STARTSCREEN_PLAY:
			startMenuPointerRect = pointerRectStart;
			break;
		case STARTSCREEN_QUIT:
			startMenuPointerRect = pointerRectQuit;
			break;
		default:
			break;
		}
	}
	else if (menustate == GameState::GAMESTATE_PAUSED)
	{
		switch (pauseSelected)
		{
		case PAUSE_RESUME:
			pauseMenuPointerRect = pausePointerRectPlay;
			break;
		case PAUSE_QUIT:
			pauseMenuPointerRect = pausePointerRectQuit;
			break;
		default:
			break;
		}
	}
}

void Menus::DisplayMenu()
{
	switch (menustate)
	{
	case GAMESTATE_START:
		renderer->UIDraw(backgroundRect, StartBackground);
		renderer->UIDraw(startMenuPointerRect, selectedArrow);
		for (int i = 0; i < startMenuTexts.size(); i++)
		{
			renderer->UIDraw(startMenuTexts[i]->textRect, startMenuTexts[i]->GetTexture());
		}
		break;

	case GAMESTATE_PAUSED:
		renderer->UIDraw(backgroundRect, pauseOverlay);
		renderer->UIDraw(pauseMenuPointerRect, selectedArrow);

		for (int i = 0; i < pauseMenuTexts.size(); i++)
		{
			renderer->UIDraw(pauseMenuTexts[i]->textRect, pauseMenuTexts[i]->GetTexture());
		}
		break;

	case GAMESTATE_INGAME:
		hud->DisplayHUD();
		break;

	default:
		break;
	}
}

void Menus::PauseGame(GameState& gameState)
{
	menustate = GameState::GAMESTATE_PAUSED;
	gameState = menustate;
}

void Menus::UnpauseGame(GameState& gameState)
{
	menustate = GameState::GAMESTATE_INGAME;
	gameState = menustate;
}
