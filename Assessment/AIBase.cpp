#include "Source/Entity.h"
#include "Vector2.h"
#include "Renderer.h"
#include "AIBase.h"

void AIBase::Update(float deltaTime)
{
	if (currentPath.size() > 0)
	{
		Vector2 direction = (currentPath[0] * Renderer::GetBlockSize()) - Vector2{ parentEntity->x, parentEntity->y };
		parentEntity->x += direction.x * deltaTime;
		parentEntity->y += direction.y * deltaTime;
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
