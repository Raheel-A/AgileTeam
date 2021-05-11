#pragma once
#include <SDL_mixer.h>
#include <string>

using namespace std;

enum SFXList
{
	Shoot,
	Walk,
	Score,
	Life,
	Damage,
	UIpositive,
	UInegative,
	MenuPop,
	Die,
};

enum music 
{
	BGM,
	Menu
};

class SoundManager
{
private:
	Mix_Chunk* sfxShoot = NULL;
	Mix_Chunk* sfxWalk = NULL;
	Mix_Chunk* sfxScore = NULL;
	Mix_Chunk* sfxLife = NULL;
	Mix_Chunk* sfxDamage = NULL;
	Mix_Chunk* sfxUIpositive = NULL;
	Mix_Chunk* sfxUInegative = NULL;
	Mix_Chunk* sfxUIpop = NULL;
	Mix_Chunk* sfxDie = NULL;
	Mix_Music* bgmMusic = NULL;
	Mix_Music* menuMusic = NULL;
public:

	SoundManager();
	~SoundManager();
	void ChangeVolume(int volume);
	void LoadMusic(music type,string path);
	void LoadSFXs(SFXList sfx, string path);
	void PlaySFX(SFXList sfx);
	void PlayBGM(music type, int loops);

};

