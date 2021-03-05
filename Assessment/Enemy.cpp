#include "Enemy.h"

void Enemy::loseHealth(int healthAmount)
{
	//after losing health, the enemy won't die
	if (m_healthPoints - healthAmount >= 0)
	{
		m_healthPoints -= healthAmount;
	}
	else //if the damage the enemy takes makes their health points be 0 or lower, they have died
	{
		m_healthPoints = 0;
		enemyDeath();
	}
}

void Enemy::attackPlayer()
{
	//call Player's lose health, among others
}

void Enemy::enemyDeath()
{
	//death method
}
