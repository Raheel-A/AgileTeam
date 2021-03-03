#pragma once
#include "SDL.h"
#include <vector>

using namespace std;

class HUD
{
public:
	void AddText(Text* t);
	void AddImage(Image* image);

	void CreateHUD();
	void DisplayHUD();

	void MoveText(Text* t, int newX, int newY);
	void MoveImage(Image* image, int newX, int newY);

	//vector<Text*> activeTexts; 		//vector of texts to add to and access?
	//vector<Image*> activeImages;		//vector of imagesto add to and access?
private:

};

