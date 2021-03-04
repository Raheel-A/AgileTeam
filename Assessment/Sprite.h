/* Change Log
-Seb
04/03/2021 Chase - Adding a get sprite function to get the texture for map loader
*/
#pragma once
#include "SDL.h"

struct Vector2 { int x, y; };

class Sprite
{
public:
	Sprite(SDL_Texture* text);
	Vector2 getPos();
	void setPos(Vector2 newPos);

	//CW
	SDL_Texture* GetSprite();
private:
	Vector2 pos = { 0,0 };
	SDL_Texture* sprite;
};

