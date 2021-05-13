#include "Source/Entity.h"
#include "Vector2.h"
#include "Source/Player.h"
#include "GameManager.h"
#include "Pathfinder.h"
#include "Renderer.h"
#include "AIBase.h"

AIBase::AIBase(Entity* owner)
{
	parentEntity = owner;
	targetEntity = GameManager::instance().player;
}

void AIBase::Update(float deltaTime)
{
	if (pathfindingTimer > 0)
	{
		pathfindingTimer -= deltaTime;
	}

	if (currentPath.size() > 0)
	{
		Vector2 direction = (currentPath[0] + Vector2{0.5f, 0.5f} - parentEntity->GetPositionInTileMap(Vector2(parentEntity->x, parentEntity->y))).Normalised();

		parentEntity->x += direction.x * parentEntity->speed * deltaTime;
		parentEntity->y += direction.y * parentEntity->speed * deltaTime;

		parentEntity->sprite->setPos(Vector2(parentEntity->x, parentEntity->y));

		Vector2 selfPos = parentEntity->GetPositionInTileMap(Vector2(parentEntity->x, parentEntity->y));
		if (selfPos.Distance(currentPath[0] + Vector2{0.5f, 0.5f}) < 0.01f)
		{
			currentPath.erase(currentPath.begin());
		}
	}
	else if (targetEntity != nullptr)
	{
		if (pathfindingTimer <= 0)
		{
			GoTo(targetEntity->GetPositionInTileMap(Vector2{ targetEntity->x-30,targetEntity->y-30 }));
		}
	}
}

void AIBase::SetParentLevel(LevelData* level)
{
	parentLevel = level;
}

void AIBase::GoTo(Vector2 destination)
{
	Vector2 selfPos = parentEntity->GetPositionInTileMap(Vector2{ parentEntity->x,parentEntity->y });
	currentPath = GameManager::instance().pathfinder->FindPath(selfPos, destination);
	pathfindingTimer = 0.5f;
}

void AIBase::Stop(Vector2 destination)
{
	currentPath = {};
}
