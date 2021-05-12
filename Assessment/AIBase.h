#pragma once
#include <vector>
#include "Vector2.h"

class Entity;
class LevelData;

class AIBase
{
public:
	bool isEnabled = true;

	void Update(float deltaTime);
	void SetParentLevel(LevelData* level); //TODO this could be handled in ctor

	void GoTo(Vector2 destination);
	void Stop(Vector2 destination);
	virtual void Attack(Entity& target) = 0;

protected:
	std::vector<Vector2> currentPath = {};
	LevelData* parentLevel = nullptr;
	Entity* parentEntity = nullptr;
	Entity* targetEntity = nullptr;
	float playerDetectionRange = 150;
	float playerLostRange = 300;
};

