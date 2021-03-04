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

int Player::GetLives()
{
	return lives;
}
