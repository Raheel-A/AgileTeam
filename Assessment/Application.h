#pragma once

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
#include "Player.h"
#include "InputSystem/Input.h"

class Application
{
public:
	Application();
	~Application();

	bool initApp();
	void loopApp();


private:

	Renderer* m_renderer;

	Input* m_input;

	bool m_quit;


};

