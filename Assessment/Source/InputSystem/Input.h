#pragma once
#include "SDL.h"

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
	void UpdateInstance();
	static void Update();
	static bool KeyIsDown(KEY_LIST key);
private:
	static SDL_Event inputEvent;
	static bool keysPressed[SIZEOF_KEY_LIST];
};

