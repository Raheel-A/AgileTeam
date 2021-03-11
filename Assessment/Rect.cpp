#include "rect.h"
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.h"

Rect::Rect(const Window& window, const char* path, int w, int h, int x, int y, int r, int g, int b, int a,bool isAnimated) :
	Window(window), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
	animated = isAnimated;
	Srcrect.x = Srcrect.x = 0;
	Srcrect.w = Srcrect.h = 32;
	DestRect.w = DestRect.h = 64;
	animated = true;

	//Creating Animations
	Animation Idle = Animation(0, 3, 100);
	Animation Walk = Animation(1, 8, 100);

	//
	anims.emplace("Idle", Idle);
	anims.emplace("Walk", Walk);


	//playing an animation
	PlayAnimation("Idle");
	SetTexture(path);
}


void Rect::Draw() const
{

	TextureManager::Draw(PlayerTexture, Srcrect, DestRect,SpriteFlip);
	
}

void Rect::pollEvents(SDL_Event &event)
{
	if (animated)
	{
		Srcrect.x = Srcrect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
	}
	Srcrect.y = animationIndex * _h; //when not animated
	DestRect.x = _x;
	DestRect.y = _y;
	DestRect.w = _w * 2; //
	DestRect.h = _h * 2; //MULTIPLY BY SCALE
		if (event.type == SDL_KEYDOWN)
		{
			
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				_x -= 10;
				PlayAnimation("Walk");
				SpriteFlip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_RIGHT:
				PlayAnimation("Idle");
				_x += 10;
				break;
			case SDLK_UP:
				PlayAnimation("Walk");
				_y -= 10;
				break;
			case SDLK_DOWN:
				PlayAnimation("Walk");
				_y += 10;
				break;
			default:
				break;


			}
		}
}

Rect::~Rect()
{
	SDL_DestroyTexture(PlayerTexture);
}

void Rect::SetTexture(const char* path)
{
	PlayerTexture = TextureManager::LoadTexture(path);
}

void Rect::PlayAnimation(const char* Name)
{
	//Finds animation put in and returns appropraite information
	frames = anims[Name].Frames;
	animationIndex = anims[Name].Index;
	speed = anims[Name].Speed;
}


