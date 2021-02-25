#pragma once
#include <string>
#include "SDL.h"
class ImageLoader
{
public:
	ImageLoader(SDL_Renderer* rend);
	~ImageLoader();
	void LoadeImage(std::string path);
	SDL_Texture* GetImage(); 
private:
	SDL_Surface* surface;
	SDL_Texture* image;
	SDL_Renderer* renderer;
	bool useTransparency;

};

