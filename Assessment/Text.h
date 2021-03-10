#pragma once
#include <SDL_ttf.h>
#include <string>

class Text
{
public:
	Text(const char* fontFile, SDL_Color col, int size, std::string text, int x, int y);
	~Text();

	void UpdateText(std::string actualText);
	void UpdateText(std::string actualText, SDL_Color col);

	//Text Attributes
	TTF_Font* font = nullptr;
	SDL_Color fontColour = { 0, 255, 0, 255 }; //r g b a -- green
	int fontSize = 0;
	std::string fonttext = "";

	//Rendering
	//Renderer* renderer = nullptr;
	SDL_Rect textRect;
	SDL_Texture* fontTexture = nullptr;

	void CreateTextTexture();

};