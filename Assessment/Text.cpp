#include "Text.h"



Text::Text(SDL_Renderer* r, int size, std::string text, int x, int y)
{
	rend = r;

	font = TTF_OpenFont(fontPath, size);

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

	CreateTextTexture();
}

void Text::CreateTextTexture()
{
	SDL_Surface* surface = TTF_RenderText_Solid(font, fonttext.c_str(), black);

	if (surface == NULL)
	{
		printf("Text Render Error: %s\n", TTF_GetError());
	}

	fontTexture = SDL_CreateTextureFromSurface(rend, surface);

	if (fontTexture == NULL)
	{
		printf("Text Texture Creation Error: %s\n", SDL_GetError());
	}

	SDL_FreeSurface(surface);
}
