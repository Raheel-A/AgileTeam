#pragma once
#include <SDL_mixer.h>
#include <string>

using namespace std;

enum SFXList
{
	Shoot,
	Footsteps,

};

class SoundManager
{
private:
	Mix_Chunk* sfxShoot = NULL;
	Mix_Music* bgmMusic = NULL;
public:

	SoundManager();
	~SoundManager();
	void ChangeVolume(int volume);
	void LoadMusic(string path);
	void LoadSFXs(SFXList sfx, string path);
	void PlaySFX(SFXList sfx);
	void PlayBGM(int loops);

};

