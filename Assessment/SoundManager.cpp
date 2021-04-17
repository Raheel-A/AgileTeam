#include "SoundManager.h"

SoundManager::SoundManager()
{
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

SoundManager::~SoundManager()
{
	//Close BGM
	Mix_FreeMusic(bgmMusic);
	bgmMusic = NULL;

	Mix_FreeChunk(sfxShoot);

	sfxShoot = NULL;

	Mix_Quit();
}

void SoundManager::PlayBGM(int loops)
{
	Mix_PlayMusic(bgmMusic, loops);
}

void SoundManager::ChangeVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

void SoundManager::LoadMusic(string path)
{
	const char* BGMpath = path.c_str();
	//Load music
	bgmMusic = Mix_LoadMUS(BGMpath);
	if (bgmMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void SoundManager::LoadSFXs(SFXList sfx, string path)
{
	const char* SFXpath = path.c_str();

	switch (sfx)
	{
	case Shoot:
		sfxShoot = Mix_LoadWAV(SFXpath);
		Mix_VolumeChunk(sfxShoot, 5);
		if (sfxShoot == NULL)
		{
			printf("Failed to load Jump sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;

	default:
		break;
	}
}

void SoundManager::PlaySFX(SFXList sfx)
{
	switch (sfx)
	{
	case Shoot:
		Mix_PlayChannel(-1, sfxShoot, 0);
		break;


	default:
		break;
	}
}

