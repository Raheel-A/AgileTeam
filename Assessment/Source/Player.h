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

	//stats
	unsigned int m_healthPoints{ 100 };
	unsigned int m_attackPoints{ 50 };
	float m_movementSpeed{ 3.5f };

	//checks
	bool hasDied;

	//methods
	void LoseHealth(int healthAmount);
	void GainHealth(int healthAmount);

	void Init();
	void Update(float delta);
	void Draw();

	void OnCollision(Entity* collider);

	int GetLives();

	void PlayerAttack();

	void PlayerDeath();
private:
	int lives = 10;
};