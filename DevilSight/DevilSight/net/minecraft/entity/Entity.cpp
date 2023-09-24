#include "Entity.h"
#include "../client/Minecraft.h"

jclass playerClass = NULL;

jobject playerObject = NULL;
jfieldID getPlayerField = NULL;

jmethodID setSprintingMethod = NULL;

jfieldID motionXField = NULL;
jfieldID motionYField = NULL;
jfieldID motionZField = NULL;

jfieldID hurtResistantTimeField = NULL;

jclass C_Entity::getClass()
{
	if (playerClass == NULL)
		playerClass = ct.env->FindClass("bew");

	return playerClass;
}

jobject C_Entity::getInstance()
{
	if (getPlayerField == NULL)
		getPlayerField = ct.env->GetFieldID(C_Minecraft::getClass(), "h", "Lbew;");

	if (playerObject == NULL)
		playerObject = ct.env->GetObjectField(C_Minecraft::getInstance(), getPlayerField);

	return playerObject;
}

void C_Entity::setSprinting(bool state)
{
	if (setSprintingMethod == NULL)
		setSprintingMethod = ct.env->GetMethodID(getClass(), "d", "(Z)V");

	ct.env->CallBooleanMethod(getInstance(), setSprintingMethod, state);
}

jdouble C_Entity::getMotionX()
{
	if (motionXField == NULL)
		motionXField = ct.env->GetFieldID(getClass(), "v", "D");

	return ct.env->GetDoubleField(getInstance(), motionXField);
}

jdouble C_Entity::getMotionY()
{
	if (motionYField == NULL)
		motionYField = ct.env->GetFieldID(getClass(), "w", "D");

	return ct.env->GetDoubleField(getInstance(), motionYField);
}

jdouble C_Entity::getMotionZ()
{
	if (motionZField == NULL)
		motionZField = ct.env->GetFieldID(getClass(), "x", "D");

	return ct.env->GetDoubleField(getInstance(), motionZField);
}

void C_Entity::setMotionX(jdouble value)
{
	ct.env->SetDoubleField(getInstance(), motionXField, value);
}

void C_Entity::setMotionY(jdouble value)
{
	ct.env->SetDoubleField(getInstance(), motionYField, value);
}

void C_Entity::setMotionZ(jdouble value)
{
	ct.env->SetDoubleField(getInstance(), motionZField, value);
}

jint C_Entity::getHurtResistantTime()
{
	if (hurtResistantTimeField == NULL)
		hurtResistantTimeField = ct.env->GetFieldID(getClass(), "Z", "I");

	return ct.env->GetIntField(getInstance(), hurtResistantTimeField);
}