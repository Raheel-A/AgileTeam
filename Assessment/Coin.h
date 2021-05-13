#pragma once
#include "Source/Entity.h"


class Coin :
    public Entity
{
public:
    void Init();
    void Update(float delta);
    void Draw(int cameraX, int cameraY);
    void LoadSprite(ImageLoader* imageLoader);
    void OnCollision(Entity* collider);
};

