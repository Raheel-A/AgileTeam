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
	AddImage(background); //0

	//weapon icon
	imageLoader->LoadeImage(weaponIconPath);
	weaponIcon = imageLoader->GetImage();
	AddImage(weaponIcon); //1

	//health icons
	imageLoader->LoadeImage(heartImagePath);
	heartIcon = imageLoader->GetImage();
	AddImage(heartIcon); //2

	imageLoader->LoadeImage(blankHeartPath);
	blankHeart = imageLoader->GetImage();
	AddImage(blankHeart); //3

	//create text
	moneyText = new Text(sdl_rend, 30, money, 0, 0);
	AddText(moneyText); //0

	healthText = new Text(sdl_rend, 30, health, 530, 0);
	AddText(healthText); //1

	weaponText = new Text(sdl_rend, 20, weaponName, 0, 490);
	AddText(weaponText); //2
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

	DisplayHealth();

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

/// <summary>
/// Displays the correct amount of hearts depending on the lives of the player
/// </summary>
void HUD::DisplayHealth()
{
	switch (lives)
	{
	case 3:
		renderer->UIDraw(livesRect1, activeImages[2]);
		renderer->UIDraw(livesRect2, activeImages[2]);
		renderer->UIDraw(livesRect3, activeImages[2]);
		break;
	case 2:
		renderer->UIDraw(livesRect1, activeImages[2]);
		renderer->UIDraw(livesRect2, activeImages[2]);
		renderer->UIDraw(livesRect3, activeImages[3]);
		break;
	case 1:
		renderer->UIDraw(livesRect1, activeImages[2]);
		renderer->UIDraw(livesRect2, activeImages[3]);
		renderer->UIDraw(livesRect3, activeImages[3]);
		break;
	case 0:
		renderer->UIDraw(livesRect1, activeImages[3]);
		renderer->UIDraw(livesRect2, activeImages[3]);
		renderer->UIDraw(livesRect3, activeImages[3]);
		break;
	default:
		break;
	}
}

void HUD::ChangeHealth(int change)
{
	lives += change;

	if (lives > 3)
	{
		lives = 3;
	}
	else if (lives < 0)
	{
		lives = 0;
	}
}

void HUD::ChangeGold(int change)
{
	gold += change;

	money = "Gold: " + to_string(gold);

	moneyText->UpdateText(money);
}
