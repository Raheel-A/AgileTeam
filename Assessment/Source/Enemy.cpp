#include "../AIMelee.h"
#include "../Renderer.h"
#include "Player.h"
#include "Enemy.h"

Enemy::Enemy() : Enemy(0, 0, 10, 10)
{
}

Enemy::Enemy(float x, float y, float width, float height) : Entity(x, y, width, height)
{
	entityType = EntityTypes::ENEMY;
	ai = new AIMelee(this);
	speed = Renderer::GetBlockSize() * 6;
}

void Enemy::Init()
{
}

void Enemy::Update(float delta)
{
	ai->Update(delta);
	UpdateCollisionBox();
}

void Enemy::Draw(int cameraX, int cameraY)
{
	// TODO: This can probably moved to the Entity class
	if (sprite != nullptr)
	{
		sprite->SpriteUpdate(cameraX, cameraY);
		sprite->Draw();
	}
}

void Enemy::LoadSprite(ImageLoader* imageLoader)
{
	sprite = new Sprite(imageLoader->LoadeImage("Assets/evil_pumpkin_dude.bmp"), true);
	sprite->setPos(Vector2(x, y));
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

void Enemy::AttackPlayer(int damageAmount)
{
	//call Player's lose health, among others
	player->LoseHealth(damageAmount);
}

void Enemy::EnemyDeath()
{
	//death method
}

Enemy::~Enemy()
{
	delete ai;
}
