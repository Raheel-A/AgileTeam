#include "Sprite.h"

Sprite::Sprite(SDL_Texture* text)
{
    sprite = text;
}

Vector2 Sprite::getPos()
{
    return pos;
}

void Sprite::setPos(Vector2 newPos)
{
    pos = newPos;
}
