#pragma once

struct Animation
{
public:
	int Index;
	int Frames;
	int Speed;

	Animation() {};
	Animation(int index, int frames, int speed)
	{
		Index = index;
		Frames = frames;
		Speed = speed;
	}

};
