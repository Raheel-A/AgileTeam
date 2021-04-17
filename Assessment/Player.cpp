#include "Player.h"

void Player::loseHealth(int healthAmount)
{
	//after losing health, the player won't die
	if (m_healthPoints - healthAmount >= 0)
	{
		m_healthPoints -= healthAmount;
	}
	else //if the damage the player takes makes their health points be 0 or lower, they have died
	{
		m_healthPoints = 0;
		playerDeath();
	}
}

void Player::gainHealth(int healthAmount)
{
	//if by gaining health the health points don't exceed the maximum, add it to the current HP
	if (m_healthPoints + healthAmount <= 100)
	{
		m_healthPoints += healthAmount;
	}
	else //leave the player health's to its initial maximum in case the health amount is bigger than the maximum
	{
		m_healthPoints = 100;
	}
}

void Player::playerAttack()
{
	//attack method
}

void Player::playerDeath()
{
	//death method
	hasDied = true;
}
