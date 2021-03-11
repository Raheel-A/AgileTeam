#pragma once
#include <SDL.h>
#include <iostream>
#include <map>

struct Animation
{
public:
	int Index;
	int Frames;
	int Speed;

	Animation() {};
	Animation(int index, int frames, int speed)
	{
		Index = index;
		Frames = frames;
		Speed = speed;
	}
	int AnimIndex = 0;//if we dont animate our sprite then the initial y position of the sprite needs to be at 0
	std::map < const char*, Animation> anims; //will be holding the animations
	SDL_RendererFlip SpriteFlipMode = SDL_FLIP_NONE;

	/*PlayerPosition;*/
	SDL_Texture* texture;
	SDL_Rect SrcRect, DestRect;

private:




};
