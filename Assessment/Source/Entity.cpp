#include "Entity.h"

Entity::Entity(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	UpdateCollisionBox();
}

Entity::~Entity()
{
}

void Entity::UpdateCollisionBox()
{
	collisionBox.x = x;
	collisionBox.y = y;
	collisionBox.w = width;
	collisionBox.h = height;
}

bool Entity::CheckCollision(Entity* entity1, Entity* entity2)
{
	if (entity1->collisionBox.x < entity2->collisionBox.x + entity2->collisionBox.w && // Left e1 < right e2
		entity1->collisionBox.x + entity1->collisionBox.w > entity2->collisionBox.x && // Right e1 > left e2
		entity1->collisionBox.y < entity2->collisionBox.y + entity2->collisionBox.h && // Top e1 < bottom e2
		entity1->collisionBox.y + entity1->collisionBox.h > entity2->collisionBox.y)   // Bottom e1 > top e2
	{
		return true;
	}

	return false;
}

bool Entity::CheckCollision(Entity* entity, SDL_Rect rect)
{
	//Check for collision between entity and rect - for attack range colliders
	if (entity->collisionBox.x < rect.x + rect.w && // Left e1 < right e2
		entity->collisionBox.x + entity->collisionBox.w > rect.x && // Right e1 > left e2
		entity->collisionBox.y < rect.y + rect.h && // Top e1 < bottom e2
		entity->collisionBox.y + entity->collisionBox.h > rect.y)   // Bottom e1 > top e2
	{
		return true;
	}

	return false;
}

int Entity::GetX()
{
	return x;
}

int Entity::GetY()
{
	return y;
}


