#pragma once
#include <string>

#include "Entity.h";

using namespace std;

class Enemy : public Entity
{
public:
	//data
	string enemyType;

	//methods
	Enemy();
	Enemy(float x, float y, float width, float height);
	~Enemy();

	void Init();
	void Update(float delta);
	void Draw();
	void LoadSprite(ImageLoader* imageLoader);

	void OnCollision(Entity* collider);

	void LoseHealth(int healthAmount);

	void AttackPlayer();

	void EnemyDeath();


private:

};

