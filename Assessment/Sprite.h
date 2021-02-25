#pragma once
#include "SDL.h"

struct Vector2 { int x, y; };

class Sprite
{
public:
	Sprite(SDL_Texture* text);
	Vector2 getPos();
	void setPos(Vector2 newPos);
private:
	Vector2 pos = { 0,0 };
	SDL_Texture* sprite;
};

