#pragma once
#include "SDL/include/SDL.h"

enum KEY_LIST {
	KEY_ESC,
	KEY_UP,
	KEY_LEFT,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_SPACE,
	KEY_LSHIFT,
	SIZEOF_KEY_LIST
};
class Input
{
public:
	Input();
	~Input();
	void Update();
	bool KeyIsDown(KEY_LIST key);
private:
	SDL_Event inputEvent;
	bool keysPressed[SIZEOF_KEY_LIST];
};

