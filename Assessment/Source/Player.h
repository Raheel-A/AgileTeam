#pragma once
#include "Entity.h";
#include "Enemy.h"

/// <summary>
/// Entity that is controlled by the player and stores the health
/// </summary>
class Player : public Entity
{
public:
	Player();
	Player(float x, float y, float width, float height);
	~Player();

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

	void PlayerAttack();

	void PlayerDeath();
	
private:
	int attackRange;
	SDL_Rect attackRangeCollisionBox;

	void UpdateAttackRangeCollider();
	Vector2 GetPlayerPositionInTileMap(Vector2 position);
};