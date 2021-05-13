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
	Mix_FreeMusic(menuMusic);
	menuMusic = NULL;
	bgmMusic = NULL;

	Mix_FreeChunk(sfxShoot);
	Mix_FreeChunk(sfxDamage);
	Mix_FreeChunk(sfxDie);
	Mix_FreeChunk(sfxLife);
	Mix_FreeChunk(sfxScore);
	Mix_FreeChunk(sfxUInegative);
	Mix_FreeChunk(sfxUIpop);
	Mix_FreeChunk(sfxUIpositive);
	Mix_FreeChunk(sfxWalk);

	sfxShoot = NULL;
	sfxDamage = NULL;
	sfxDie = NULL;
	sfxLife = NULL;
	sfxScore = NULL;
	sfxUInegative = NULL;
	sfxUIpop = NULL;
	sfxUIpositive = NULL;
	sfxWalk = NULL;

	Mix_Quit();
}

void SoundManager::PlayBGM(music type,int loops)
{
	switch (type)
	{
	case BGM:
		Mix_PlayMusic(bgmMusic, loops);
		break;
	case Menu:
		Mix_PlayMusic(menuMusic, loops);
		break;
	default:
		break;
	}
	
}

void SoundManager::ChangeVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

void SoundManager::LoadMusic(music type,string path)
{
	const char* BGMpath = path.c_str();
	//Load music

	switch (type)
	{
	case BGM:
		bgmMusic = Mix_LoadMUS(BGMpath);
		if (bgmMusic == NULL)
		{
			printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;
	case Menu:
		menuMusic = Mix_LoadMUS(BGMpath);
		if (menuMusic == NULL)
		{
			printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;
	default:
		break;
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
	case Walk:
		sfxWalk = Mix_LoadWAV(SFXpath);
		Mix_VolumeChunk(sfxWalk, 5);
		if (sfxWalk == NULL)
		{
			printf("Failed to load Jump sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;
	case Score:
		sfxScore = Mix_LoadWAV(SFXpath);
		Mix_VolumeChunk(sfxScore, 5);
		if (sfxScore == NULL)
		{
			printf("Failed to load Jump sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;
	case Life:
		sfxLife = Mix_LoadWAV(SFXpath);
		Mix_VolumeChunk(sfxLife, 5);
		if (sfxLife == NULL)
		{
			printf("Failed to load Jump sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;
	case Damage:
		sfxDamage = Mix_LoadWAV(SFXpath);
		Mix_VolumeChunk(sfxDamage, 5);
		if (sfxDamage == NULL)
		{
			printf("Failed to load Jump sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;
	case UIpositive:
		sfxUIpositive = Mix_LoadWAV(SFXpath);
		Mix_VolumeChunk(sfxUIpositive, 5);
		if (sfxUIpositive == NULL)
		{
			printf("Failed to load Jump sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;
	case UInegative:
		sfxUInegative = Mix_LoadWAV(SFXpath);
		Mix_VolumeChunk(sfxUInegative, 5);
		if (sfxUInegative == NULL)
		{
			printf("Failed to load Jump sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;
	case MenuPop:
		sfxUIpop = Mix_LoadWAV(SFXpath);
		Mix_VolumeChunk(sfxUIpop, 5);
		if (sfxUIpop == NULL)
		{
			printf("Failed to load Jump sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
		break;
	case Die:
		sfxDie = Mix_LoadWAV(SFXpath);
		Mix_VolumeChunk(sfxDie, 5);
		if (sfxDie == NULL)
		{
			printf("Failed to load Jump sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
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
	case Walk:
		Mix_PlayChannel(-1, sfxWalk, 0);
		break;
	case Score:
		Mix_PlayChannel(-1, sfxScore, 0);
		break;
	case Life:
		Mix_PlayChannel(-1, sfxLife, 0);
		break;
	case Damage:
		Mix_PlayChannel(-1, sfxDamage, 0);
		break;
	case UIpositive:
		Mix_PlayChannel(-1, sfxUIpositive, 0);
		break;
	case UInegative:
		Mix_PlayChannel(-1, sfxUInegative, 0);
		break;
	case MenuPop:
		Mix_PlayChannel(-1, sfxUIpop, 0);
		break;
	case Die:
		Mix_PlayChannel(-1, sfxDie, 0);
		break;
	}
}

