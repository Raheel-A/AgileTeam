/* Change Log
-Seb
04/03/2021 Chase - Adding a get sprite function to get the texture for map loader
*/
#pragma once
#include "SDL.h"
#include <map>
#include "Animation.h"

// changed
// san 10/03/21

struct Vector2 { int x, y; };

class Sprite
{
public:
	Sprite(SDL_Texture* text);
	Vector2 getPos();
	void setPos(Vector2 newPos);

	//CW
	SDL_Texture* GetSprite();

	//Animation
	Sprite(SDL_Texture* text, bool isAnimated);
	void PlayAnimation(const char* AnimName);
	void SpriteUpdate();
	void Draw();
	SDL_RendererFlip FlipMode = SDL_FLIP_NONE;
	bool animated = false;
	SDL_Rect SourceRect, DestRect;
	int frames = 0; //how many frames in the animation
	int speed = 100; //delay between frames in milliseconds
	int AnimIndex = 0;//if we dont animate our sprite then the initial y position of the sprite needs to be at 0
	std::map < const char*, Animation> anims; //will be holding the animations
	//Animation

private:
	Vector2 pos = { 0,0};
	SDL_Texture* sprite;

};

