#include "Source/Entity.h"
#include "Vector2.h"
#include "Source/Player.h"
#include "GameManager.h"
#include "Renderer.h"
#include "AIBase.h"

AIBase::AIBase(Entity* owner)
{
	parentEntity = owner;
	currentPath.push_back(Vector2(10, 10));
}

void AIBase::Update(float deltaTime)
{
	if (currentPath.size() > 0)
	{
		//Vector2 direction = (currentPath[0] - parentEntity->GetPositionInTileMap(Vector2(parentEntity->x, parentEntity->y))).Normalised();
		Vector2 dst = Vector2(GameManager::instance().player->GetX(), GameManager::instance().player->GetY());
		Vector2 direction = (dst - parentEntity->GetPositionInTileMap(Vector2(parentEntity->x, parentEntity->y))).Normalised();

		parentEntity->x += direction.x * parentEntity->speed * deltaTime;
		parentEntity->y += direction.y * parentEntity->speed * deltaTime;

		parentEntity->sprite->setPos(Vector2(parentEntity->x, parentEntity->y));
	}
	else if (targetEntity != nullptr)
	{
		GoTo(Vector2{ targetEntity->x, targetEntity->y });
	}
}

void AIBase::SetParentLevel(LevelData* level)
{
	parentLevel = level;
}

void AIBase::GoTo(Vector2 destination)
{
	//currentPath = parentLevel.GetPathfinder().FindPath(parentEntity.position, destination)
}

void AIBase::Stop(Vector2 destination)
{
	currentPath = {};
}
