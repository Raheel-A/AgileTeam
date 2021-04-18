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

	bool InitApp();
	void LoopApp();

private:

	Renderer* m_renderer_ptr;

	Input* m_input_ptr;

	bool m_quit;

};

