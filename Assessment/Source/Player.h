#pragma once
#include "Entity.h";

/// <summary>
/// Entity that is controlled by the player and stores the health
/// </summary>
class Player : public Entity
{
public:
	Player();
	Player(float x, float y, float width, float height);
	~Player();

	void Init();
	void Update(float delta);
	void Draw();

	void OnCollision(Entity* collider);

	int GetLives();

private:
	int lives = 10;
};