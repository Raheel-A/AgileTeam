#include "ImageLoader.h"
#include <string>

/// <summary>
/// constructor takes in the renderer 
/// </summary>
/// <param name="rend"></param>
ImageLoader::ImageLoader(SDL_Renderer* rend)
{
	renderer = rend;
}

ImageLoader::~ImageLoader()
{
}

/// <summary>
/// load a image and creat a texture based on file path 
/// </summary>
/// <param name="path">file path to the image</param>
void ImageLoader::LoadeImage(std::string path)
{
	surface = SDL_LoadBMP(path.c_str());

	if (!surface)
	{
		std::string spath = "faild to creat surface for file" + path;
		printf(spath.c_str());
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
			std::string spath = "you faild the texture wasent created" + path;
	   		printf(spath.c_str());

	   		printf(SDL_GetError());
		}
	}
}

/// <summary>
/// returns the texutre
/// </summary>
/// <returns>teh texture that was created</returns>
SDL_Texture* ImageLoader::GetImage()
{
	return image;
}

