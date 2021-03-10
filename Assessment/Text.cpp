#include "Text.h"



Text::Text(const char* fontFile, SDL_Color col, int size, std::string text, int x, int y)
{
	font = TTF_OpenFont(fontFile, size);

	fontColour = col;
	fontSize = size;
	fonttext = text;
	textRect.x = x;
	textRect.y = y;

	CreateTextTexture();

	SDL_QueryTexture(fontTexture, NULL, NULL, &textRect.w, &textRect.h);

	//printf("%s: H1: %d  W1: %d\n", fonttext.c_str(), textRect.h, textRect.w);
}


Text::~Text()
{
}

void Text::UpdateText(std::string actualText)
{
	fonttext = actualText;

	CreateTextTexture();
}

void Text::UpdateText(std::string actualText, SDL_Color col)
{
	fonttext = actualText;
	fontColour = col;

	CreateTextTexture();
}

void Text::CreateTextTexture()
{
	SDL_Surface* surface = TTF_RenderText_Solid(font, fonttext.c_str(), fontColour);

	if (surface == NULL)
	{
		printf("Text Render Error: %s\n", TTF_GetError());
	}

	//----------------------NEED THE RENDERER FOR THIS LINE------------------------
	fontTexture = SDL_CreateTextureFromSurface(Renderer::renderer, surface);

	if (fontTexture == NULL)
	{
		printf("Text Texture Creation Error: %s\n", SDL_GetError());
	}

	SDL_FreeSurface(surface);
}
