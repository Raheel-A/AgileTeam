#include "ImageLoader.h"

ImageLoader::ImageLoader(SDL_Renderer* rend)
{
	renderer = rend;
}

ImageLoader::~ImageLoader()
{
}

void ImageLoader::LoadeImage(std::string path)
{
	surface = SDL_LoadBMP(path.c_str());

	if (!image)
	{
	printf("faild to creat surface for file", path.c_str());
	printf(SDL_GetError());
	}
	else
	{
		if (useTransparency)
		{
	   		Uint32 colour = SDL_MapRGB(surface->format, 255, 0, 255);
	   		SDL_SetColorKey(surface, SDL_TRUE, colour);
		}
		//creat a texture from the surface using the renderer
		image = SDL_CreateTextureFromSurface(renderer, surface);
		//a cheak to see if it was correctly built
		if (!image)
		{
	   		printf("you faild again but this time the texture wasent created", path.c_str());
	   		printf(SDL_GetError());
		}
	}
}

SDL_Texture* ImageLoader::GetImage()
{
	return image;
}
