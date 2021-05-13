#pragma once
#include "Source/Entity.h"


class Coin :
    public Entity
{
public:
    Coin(float x, float y, float width, float height);
    void Init();
    void Update(float delta);
    void Draw(int cameraX, int cameraY);
    void LoadSprite(ImageLoader* imageLoader);
    void OnCollision(Entity* collider);
};

