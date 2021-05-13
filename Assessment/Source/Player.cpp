#include "Player.h"
#include "../Renderer.h"
#include "InputSystem/Input.h"

Player::Player() : Player(0, 0, 10, 10)
{
}

Player::Player(float x, float y, float width, float height) : Entity(x, y, width, height)
{
	x = x;
	y = y;
	speed = Renderer::GetBlockSize() * 7;

	//Setup attack range box (JW)
	attackRangeCollisionBox.x = x - attackRange;
	attackRangeCollisionBox.y = y - attackRange;
	attackRangeCollisionBox.w = width + (attackRange + attackRange);
	attackRangeCollisionBox.h = height + (attackRange + attackRange);

	entityType = EntityTypes::PLAYER;
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update(float delta)
{
	Vector2 oldPosition = Vector2(this->x, this->y);
	Vector2 newPosition = oldPosition;

	if (Input::KeyHeld(KEY_UP))
	{
		//y -= speed * delta;
		newPosition.y -= speed * delta;
	}

	if (Input::KeyHeld(KEY_LEFT))
	{
		//x -= speed * delta;
		newPosition.x -= speed * delta;
		sprite->FlipMode = SDL_FLIP_HORIZONTAL;
	}

	if (Input::KeyHeld(KEY_DOWN))
	{
		//y += speed * delta;
		newPosition.y += speed * delta;
	}

	if (Input::KeyHeld(KEY_RIGHT))
	{
		//x += speed * delta;
		newPosition.x += speed * delta;
		sprite->FlipMode = SDL_FLIP_NONE;
	}

	//Check new position for collision with the tilemap
	char charToCheck = levelData->GetTile(GetPositionInTileMap(newPosition));
	if (TILES::MOUNTAIN == charToCheck || 
		TILES::DOOR == charToCheck || 
		TILES::FENCE == charToCheck || 
		TILES::PIT == charToCheck || 
		TILES::POT == charToCheck ||
		TILES::TREES == charToCheck ||
		TILES::WALL == charToCheck) 
	{
		//There has been a collision with a tile
	}
	else 
	{
		this->x = newPosition.x;
		this->y = newPosition.y;
	}

	std::vector<Entity*> entities = levelData->GetEntities();

	for (int i = 0; i < entities.size(); i++)
	{
		if (CheckCollision(this, entities[i])) 
		{
			//There has been a collision between two entities
			switch (entities[i]->GetEntityType())
			{
			case EntityTypes::ENEMY:
				//Do enemy stuff
				std::cout << "Enemy collision" << std::endl;
				break;
			case EntityTypes::COIN:
				menu->hud->ChangeGold(soundManager, 1);
				levelData->RemoveEntity(entities[i]);
				break;
			default:
				break;
			}
		}

		if (entities[i]->GetEntityType() == EntityTypes::ENEMY && CheckCollision(entities[i], this->attackRangeCollisionBox)) {
			std::cout << "Enemy within attack range" << std::endl;
			levelData->RemoveEntity(entities[i]);
			//PlayerAttack(attackPoints, entities[i]);
		}
				
	}

	sprite->setPos(Vector2(x, y));

	UpdateAttackRangeCollider(); //(JW)
	UpdateCollisionBox();
}

void Player::Draw(int cameraX, int cameraY)
{
	// TODO: This can probably moved to the Entity class
	if(sprite != nullptr)
	{ 
		sprite->SpriteUpdate(cameraX, cameraY);
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

int Player::GetLives()
{
	return m_healthPoints;
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

void Player::PlayerAttack(int damageAmount, Entity* enemy)
{
	enemy->LoseHealth(damageAmount);
}

void Player::PlayerDeath()
{
	//death method
	hasDied = true;
}

void Player::LoadUI(Menus* menuToLoad, SoundManager* soundManager)
{
	this->menu = menuToLoad;
	this->soundManager = soundManager;
}

void Player::UpdateAttackRangeCollider()
{
	//Update the attack range collider (JW)
	attackRangeCollisionBox.x = x - attackRange;
	attackRangeCollisionBox.y = y - attackRange;
}
