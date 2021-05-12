#pragma once
#include "AIBase.h"
class AIMelee : public AIBase
{
public:
	AIMelee(Entity* owner);
	void Attack(Entity& target);
private:
};

