#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "../Menus.h"

/// <summary>
/// Entity that is controlled by the player and stores the health
/// </summary>
class Player : public Entity
{
public:
	Player();
	Player(float x, float y, float width, float height);
	~Player();

	//classes
	//Enemy* enemy;

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
	void Draw(int cameraX, int cameraY);
	void Move(int direct);
	void LoadSprite(ImageLoader* imageLoader);

	void OnCollision(Entity* collider);

	int GetLives();

	void PlayerAttack(int damageAmount, Entity* enemy);

	void PlayerDeath();
	void LoadUI(Menus* menuToLoad, SoundManager* soundManager);
	
private:
	int attackRange;
	SDL_Rect attackRangeCollisionBox;
	Menus* menu;
	SoundManager* soundManager;

	void UpdateAttackRangeCollider();
};
