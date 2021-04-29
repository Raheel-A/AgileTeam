#include "AIBase.h"

void AIBase::Update()
{
	if (currentPath.size() > 0)
	{
		// Entity go to next position
	}
}

void AIBase::SetParentLevel(Level* level)
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
