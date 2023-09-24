#include "Velocity.h"
#include "../../net/minecraft/entity/Entity.h"

void velocityModule()
{
	if (C_Entity::getHurtResistantTime() <= 0)
		return;

	jdouble motionX = C_Entity::getMotionX();
	jdouble motionZ = C_Entity::getMotionZ();

	motionX *= 0.3;
	motionZ *= 0.3;

	C_Entity::setMotionX(motionX);
	C_Entity::setMotionZ(motionZ);
}