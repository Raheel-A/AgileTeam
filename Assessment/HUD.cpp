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
	//health icons
	imageLoader->LoadeImage(heartImagePath);
	heartIcon = imageLoader->GetImage();
	AddImage(heartIcon); //0

	imageLoader->LoadeImage(blankHeartPath);
	blankHeart = imageLoader->GetImage();
	AddImage(blankHeart); //1
	//banner
	imageLoader->LoadeImage(bannerPath);
	banner = imageLoader->GetImage();
	AddImage(banner);	//2
	//create text
	moneyText = new Text(sdl_rend, 30, money, 0, 0);
	AddText(moneyText); //0

	healthText = new Text(sdl_rend, 30, health, 530, 0);
	AddText(healthText); //1
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
	renderer->UIDraw(bannerRect, activeImages[2]);
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
	case 3: //0 = normal | 1 = blank
		renderer->UIDraw(livesRect1, activeImages[0]);
		renderer->UIDraw(livesRect2, activeImages[0]);
		renderer->UIDraw(livesRect3, activeImages[0]);
		break;
	case 2:
		renderer->UIDraw(livesRect1, activeImages[1]);
		renderer->UIDraw(livesRect2, activeImages[0]);
		renderer->UIDraw(livesRect3, activeImages[0]);
		break;
	case 1:
		renderer->UIDraw(livesRect1, activeImages[1]);
		renderer->UIDraw(livesRect2, activeImages[1]);
		renderer->UIDraw(livesRect3, activeImages[0]);
		break;
	case 0:
		renderer->UIDraw(livesRect1, activeImages[1]);
		renderer->UIDraw(livesRect2, activeImages[1]);
		renderer->UIDraw(livesRect3, activeImages[1]);
		break;
	default:
		break;
	}
}

void HUD::ChangeHealth(SoundManager* sfxMan,int change)
{
	if (change>0)
	{
		sfxMan->PlaySFX(SFXList::Life);
	}
	else
	{
		sfxMan->PlaySFX(SFXList::Damage);
	}

	lives += change;

	if (lives > 3)
	{
		lives = 3;
	}
	else if (lives < 0)
	{
		lives = 0;
		sfxMan->PlaySFX(SFXList::Die);
	}
}

void HUD::ChangeGold(SoundManager* sfxMan,int change)
{
	
	sfxMan->PlaySFX(SFXList::Score);
	gold += change;
	

	money = "Gold: " + to_string(gold);

	moneyText->UpdateText(money);
}
