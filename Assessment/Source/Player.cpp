#include "Player.h"

Player::Player() : Player(0, 0, 10, 10)
{
}

Player::Player(float x, float y, float width, float height) : Entity(x, y, width, height)
{
	this->lives = 100;

	x = x;
	y = y;
	speed = 2.0f;

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

void Player::Move(int direct)
{
	if (direct == 1) //up
	{
		y -= speed;
	}
	else if (direct == 2) //left
	{
		x -= speed;
	}
	else if (direct == 3) //down
	{
		y += speed;
	}
	else if (direct == 4) //right
	{
		x += speed;
	}
}

void Player::OnCollision(Entity* collider)
{
}

int Player::GetLives()
{
	return lives;
}
