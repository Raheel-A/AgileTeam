#include "Source/Entity.h"
#include "AIMelee.h"


AIMelee::AIMelee(Entity* owner) :AIBase(owner)
{
}

void AIMelee::Attack(Entity& target)
{
	targetEntity = &target;
}
