#include "Application.h"

/// <summary>
/// Initalizes values
/// </summary>
Application::Application()
	:m_renderer_ptr(nullptr), m_input_ptr(nullptr), m_quit(false)
{
	std::cout << "Application Initialized" << std::endl;
}

/// <summary>
/// Deletes objects and properly quits SDL
/// </summary>
Application::~Application()
{
	if (m_renderer_ptr != nullptr)
	{
		delete m_renderer_ptr;
		m_renderer_ptr = nullptr;
	}

	if (m_input_ptr != nullptr)
	{
		delete m_input_ptr;
		m_input_ptr = nullptr;
	}

	SDL_Quit();

	std::cout << "Application Deleted" << std::endl;
}

/// <summary>
/// Sets up SDL and libraries and creates the approriate objects
/// </summary>
/// <returns>Returns success or failure or initalization</returns>
bool Application::InitApp()
{
	//Init SDL + libraries

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Could not initialise SDL, SDL Error:" << SDL_GetError() << std::endl;
		return false;
	}
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cout << "Could not initialise SDL_Image, SDL_Image Error:" << IMG_GetError() << std::endl;
		return false;
	}
	if (TTF_Init())
	{
		std::cout << "Could not initialise SDL_TTF, SDL_TTF Error:" << TTF_GetError() << std::endl;
		return false;
	}
	if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3)
	{
		std::cout << "Could not initialise SDL_Mixer, SDL_Mixer Error:" << Mix_GetError() << std::endl;
		return false;
	}

	//Init objects

	m_renderer_ptr = new Renderer();

	m_input_ptr = new Input();

	//Create SDL window
	
	m_renderer_ptr->CreateWindow("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	return true;
}

/// <summary>
/// Main loop of the application
/// </summary>
void Application::LoopApp()
{
	// Collision test
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

	while (!m_quit)
	{
		m_input_ptr->Update();
		m_quit = m_input_ptr->KeyIsDown(KEY_ESC) ? true : false;

		//Check input and move accordingly 
		if (m_input_ptr->KeyIsDown(KEY_UP))
		{
			p1->Move(1);
		}

		if (m_input_ptr->KeyIsDown(KEY_LEFT))
		{
			p1->Move(2);
		}

		if (m_input_ptr->KeyIsDown(KEY_DOWN))
		{
			p1->Move(3);
		}

		if (m_input_ptr->KeyIsDown(KEY_RIGHT))
		{
			p1->Move(4);
		}

	}
}
