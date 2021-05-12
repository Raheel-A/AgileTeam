#include "Source/Entity.h"
#include "AIMelee.h"


void AIMelee::Attack(Entity& target)
{
	targetEntity = &target;
}
