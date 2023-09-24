#include "velocity.h"
#include "../../net/minecraft/entity/Entity.h"

void velocityModule()
{
	if (C_Entity::GetHurtResistantTime() <= 0)
		return;

	jdouble motionX = C_Entity::GetMotionX();
	jdouble motionZ = C_Entity::GetMotionZ();

	motionX *= 0.3;
	motionZ *= 0.3;

	C_Entity::SetMotionX(motionX);
	C_Entity::SetMotionZ(motionZ);
}