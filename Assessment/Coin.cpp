#include "Coin.h"

Coin::Coin(float x, float y, float width, float height) : Entity(x, y, width, height)
{
	entityType = EntityTypes::COIN;
}

void Coin::Init()
{
}

void Coin::Update(float delta)
{
}

void Coin::Draw(int cameraX, int cameraY)
{
	// TODO: This can probably moved to the Entity class
	if (sprite != nullptr)
	{
		sprite->SpriteUpdate(cameraX, cameraY, width, height);
		sprite->Draw();
	}
}

void Coin::LoadSprite(ImageLoader* imageLoader)
{
	sprite = new Sprite(imageLoader->LoadeImage("Assets/bitcoin.bmp"), false, 32, 32);
	sprite->setPos(Vector2(x, y));
}

void Coin::OnCollision(Entity* collider)
{
}
