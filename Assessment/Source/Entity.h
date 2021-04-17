#pragma once
#include <SDL_rect.h>

/// <summary>
/// Base class that any entity in the game derives from
/// </summary>
class Entity
{
public:
	Entity(float x, float y, float width, float height);
	~Entity();

	virtual void Init() = 0;
	virtual void Update(float delta) = 0;
	virtual void Draw() = 0;

	bool CheckCollision(Entity* entity1, Entity* entity2);
	bool CheckCollision(Entity* entity1, SDL_Rect rect2);
	virtual void OnCollision(Entity* collider) = 0;

protected:
	float x, y, z;
	float width, height;

	SDL_Rect collisionBox;

	//stats
	unsigned int healthPoints{ 100 };
	unsigned int attackPoints{ 100 };
	float movementSpeed{ 3.5f };

	float speed;

	bool collidable = true;

private:
	void UpdateCollisionBox();
};