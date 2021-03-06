#pragma once
#include <string>

#include "Entity.h"
#include "Player.h"

class AIMelee;

using namespace std;
class Enemy : public Entity
{
protected:
	friend class AIMelee;
public:
	//classes
	Player* player;

	//data
	string enemyType;

	//methods
	Enemy();
	Enemy(float x, float y, float width, float height);
	~Enemy();

	void Init();
	void Update(float delta);
	void Draw(int cameraX, int cameraY);
	void LoadSprite(ImageLoader* imageLoader);

	void OnCollision(Entity* collider);

	void LoseHealth(int healthAmount);

	void AttackPlayer(int damageAmount);

	void EnemyDeath();


private:
	AIMelee* ai;
};

