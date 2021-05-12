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
	KEY_ENTER,
	KEY_P,
	SIZEOF_KEY_LIST
};
class Input
{
public:
	Input();
	~Input();
	void UpdateInstance();
	static void Update();
	static bool KeyPressed(KEY_LIST key);
	static bool KeyHeld(KEY_LIST key);
	static void SetKeyHold();
private:
	static SDL_Event inputEvent;
	static bool keysPressed[SIZEOF_KEY_LIST];
	static bool keysHeld[SIZEOF_KEY_LIST];
};

