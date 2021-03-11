#include "Player.h"

Player::Player() : Player(0, 0, 10, 10)
{
}

Player::Player(float x, float y, float width, float height) : Entity(x, y, width, height)
{
	this->lives = 100;
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update(float delta)
{
}

void Player::Draw()
{
}

void Player::OnCollision(Entity* collider)
{
}

void Player::LoseHealth(int healthAmount)
{
	//after losing health, the player won't die
	if (m_healthPoints - healthAmount >= 0)
	{
		m_healthPoints -= healthAmount;
	}
	else //if the damage the player takes makes their health points be 0 or lower, they have died
	{
		m_healthPoints = 0;
		PlayerDeath();
	}
}

void Player::GainHealth(int healthAmount)
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

void Player::PlayerAttack()
{
	//attack method
}

void Player::PlayerDeath()
{
	//death method
	hasDied = true;
}

int Player::GetLives()
{
	return lives;
}
