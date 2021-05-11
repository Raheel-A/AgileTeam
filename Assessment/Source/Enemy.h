#pragma once
#include <string>

#include "Entity.h";
#include "Player.h";

using namespace std;

class Enemy : public Entity
{
public:
	//classes
	Player* player;

	//data
	string m_enemyType;

	//stats
	unsigned int m_healthPoints{ 100 };
	unsigned int m_attackPoints{ 100 };
	float m_movementSpeed{ 3.5f };

	//methods
	Enemy();
	Enemy(float x, float y, float width, float height);
	~Enemy();

	void Init();
	void Update(float delta);
	void Draw();

	void OnCollision(Entity* collider);

	void LoseHealth(int healthAmount);

	void AttackPlayer(int damageAmount);

	void EnemyDeath();


private:

};

