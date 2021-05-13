#include "Coin.h"

void Coin::Init()
{
}

void Coin::Update(float delta)
{
}

void Coin::Draw(int cameraX, int cameraY)
{
}

void Coin::LoadSprite(ImageLoader* imageLoader)
{
	sprite = new Sprite(imageLoader->LoadeImage("Assets/bitcoin.bmp"), true);
	sprite->setPos(Vector2(x, y));
}

void Coin::OnCollision(Entity* collider)
{
}
