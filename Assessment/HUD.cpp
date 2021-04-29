#include "HUD.h"

HUD::HUD(Renderer* r)
{
	renderer = r;
	sdl_rend = r->renderer;

	CreateHUD(sdl_rend);
}

HUD::~HUD()
{
	//delete everything
}

/// <summary>
/// 
/// </summary>
void HUD::CreateHUD(SDL_Renderer* r)
{
	//create image loader
	imageLoader = new ImageLoader(r);

	//create textures

	//background
	imageLoader->LoadeImage(backgroundPath);
	background = imageLoader->GetImage();
	AddImage(background);

	//weapon icon
	imageLoader->LoadeImage(weaponIconPath);
	weaponIcon = imageLoader->GetImage();
	AddImage(weaponIcon);

	//health icons
	imageLoader->LoadeImage(heartImagePath);
	heartIcon1 = imageLoader->GetImage();
	AddImage(heartIcon1);

	imageLoader->LoadeImage(heartImagePath);
	heartIcon2 = imageLoader->GetImage();
	AddImage(heartIcon2);

	imageLoader->LoadeImage(heartImagePath);
	heartIcon3 = imageLoader->GetImage();
	AddImage(heartIcon3);

	//create text
	moneyText = new Text(sdl_rend, 30, money, 0, 0);
	AddText(moneyText);

	healthText = new Text(sdl_rend, 30, health, 530, 0);
	AddText(healthText);

	weaponText = new Text(sdl_rend, 20, weaponName, 0, 490);
	AddText(weaponText);
}
/// <summary>
/// add a text to the hud vector ready for it to be displayed
/// </summary>
/// <param name="t">The text to be added to the HUD</param>
void HUD::AddText(Text* t)
{
	activeTexts.push_back(t);
}

/// <summary>
/// add an image to the hud ready for it to be displayed
/// </summary>
/// <param name="image">The image to be added to the HUD</param>
void HUD::AddImage(SDL_Texture* texture)
{
	activeImages.push_back(texture);
}


/// <summary>
/// Displays the images and text to the screen
/// </summary>
void HUD::DisplayHUD()
{
	renderer->UIDraw(backgroundRect, activeImages[0]);
	renderer->UIDraw(weaponRect, activeImages[1]);
	renderer->UIDraw(livesRect1, activeImages[2]);
	renderer->UIDraw(livesRect2, activeImages[3]);
	renderer->UIDraw(livesRect3, activeImages[4]);

	for (int i = 0; i < activeTexts.size(); i++)
	{
		renderer->UIDraw(activeTexts[i]->textRect, activeTexts[i]->GetTexture());
	}
}

/// <summary>
/// Move a text
/// </summary>
/// <param name="t"></param>
void HUD::MoveText(Text* t, int newX, int newY)
{
	//moves a given text to a new position
}

/// <summary>
/// Move an image
/// </summary>
/// <param name="image"></param>
void HUD::MoveImage()//Image* image, int newX, int newY)
{
	//moves a given image to a new position
}
