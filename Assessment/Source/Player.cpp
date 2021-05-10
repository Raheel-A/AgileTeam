#include "Player.h"
#include "InputSystem/Input.h"

Player::Player() : Player(0, 0, 10, 10)
{
}

Player::Player(float x, float y, float width, float height) : Entity(x, y, width, height)
{
	x = x;
	y = y;
	speed = 0.5f;

	//Setup attack range box (JW)
	attackRangeCollisionBox.x = x - attackRange;
	attackRangeCollisionBox.y = y - attackRange;
	attackRangeCollisionBox.w = width + (attackRange + attackRange);
	attackRangeCollisionBox.h = height + (attackRange + attackRange);
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update(float delta)
{
	if (Input::KeyIsDown(KEY_UP))
	{
		y -= speed * delta;
	}

	if (Input::KeyIsDown(KEY_LEFT))
	{
		x -= speed * delta;
	}

	if (Input::KeyIsDown(KEY_DOWN))
	{
		y += speed * delta;
	}

	if (Input::KeyIsDown(KEY_RIGHT))
	{
		x += speed * delta;
	}

	sprite->setPos(Vector2(x, y));

	UpdateAttackRangeCollider(); //(JW)
}

void Player::Draw()
{
	// TODO: This can probably moved to the Entity class
	if(sprite != nullptr)
	{ 
		sprite->SpriteUpdate();
		sprite->Draw();
	}
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

void Player::LoadSprite(ImageLoader* imageLoader)
{
	sprite = new Sprite(imageLoader->LoadeImage("Assets/pumpkin_dude.bmp"), true);
	sprite->setPos(Vector2(x, y));
}

void Player::LoseHealth(int healthAmount)
{
	//after losing health, the player won't die
	if (healthPoints - healthAmount >= 0)
	{
		healthPoints -= healthAmount;
	}
	else //if the damage the player takes makes their health points be 0 or lower, they have died
	{
		healthPoints = 0;
		PlayerDeath();
	}
}

void Player::GainHealth(int healthAmount)
{
	//if by gaining health the health points don't exceed the maximum, add it to the current HP
	if (healthPoints + healthAmount <= 100)
	{
		healthPoints += healthAmount;
	}
	else //leave the player health's to its initial maximum in case the health amount is bigger than the maximum
	{
		healthPoints = 100;
	}
}

void Player::PlayerAttack()
{
	//Attack method
	//If enemy in range statement - How do we Get Enemies?  Once this is decided then, 'for' loop enemies into an array
	//Also do we damage all enemies in range?  Or a single target?  How do we decide what target that is?
	//Furthermore do we have an attack speed?

	//Temp holder until decision made over how we store enemy list
	Enemy enemy;
	
	//Check if enemy is in range
	if (CheckCollision(&enemy, attackRangeCollisionBox)) {
		enemy.LoseHealth(attackPoints);
	}


}

void Player::PlayerDeath()
{
	//death method
	hasDied = true;
}

void Player::UpdateAttackRangeCollider()
{
	//Update the attack range collider (JW)
	attackRangeCollisionBox.x = x - attackRange;
	attackRangeCollisionBox.y = y - attackRange;
}
