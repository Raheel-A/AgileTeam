#pragma once
#include "Window.h"
#include <string>
#include <map>
#include "Animation.h"


class Rect : public Window
{
public :
	Rect(const Window &window, const char* path, int w, int h, int x, int y, int r, int g, int b, int a, bool isAnimated);
	/*Rect(const Window& window, int w, int h, int x, int y, const std::string& image);*/
	void Draw() const;
	void pollEvents(SDL_Event &event);
	SDL_Texture* PlayerTexture = nullptr;
	~Rect();
	void SetTexture(const char* path);
	SDL_Rect Srcrect, DestRect;
	int animationIndex = 0; //for when the sprite is not animated
	std::map<const char*, Animation> anims;//holds the animations
	void PlayAnimation(const char* Name);
	SDL_RendererFlip SpriteFlip = SDL_FLIP_NONE;
private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
	bool animated = false;
	int frames = 0; //how many frames in the animation
	int speed = 100; //delay between frames in milliseconds


};
