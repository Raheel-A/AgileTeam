#include "Enemy.h"

Enemy::Enemy() : Enemy(0, 0, 10, 10)
{
}

Enemy::Enemy(float x, float y, float width, float height) : Entity(x, y, width, height)
{
}

void Enemy::Init()
{
}

void Enemy::Update(float delta)
{
}

void Enemy::Draw()
{
}

void Enemy::OnCollision(Entity* collider)
{
}

void Enemy::LoseHealth(int healthAmount)
{
	//after losing health, the enemy won't die
	if (healthPoints - healthAmount >= 0)
	{
		healthPoints -= healthAmount;
	}
	else //if the damage the enemy takes makes their health points be 0 or lower, they have died
	{
		healthPoints = 0;
		EnemyDeath();
	}
}

void Enemy::AttackPlayer()
{
	//call Player's lose health, among others
}

void Enemy::EnemyDeath()
{
	//death method
}

Enemy::~Enemy()
{
}
