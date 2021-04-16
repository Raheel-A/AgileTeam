#pragma once
#include <vector>
#include "Vector2.h"

class SampleEntity;
class Level;

class AIBase
{
public:
	bool isEnabled = true;

	void Update();
	void SetParentLevel(Level* level); //TODO this could be handled in ctor

	void GoTo(Vector2 destination);
	void Stop(Vector2 destination);
	virtual void Attack(SampleEntity& target) = 0;

protected:
	std::vector<Vector2> currentPath = {};
	Level* parentLevel = nullptr;
	SampleEntity* parentEntity = nullptr;
	SampleEntity* targetEntity = nullptr;
	float playerDetectionRange = 10;
	float playerLostRange = 20;
};

