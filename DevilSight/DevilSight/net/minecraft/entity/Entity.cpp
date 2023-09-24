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
jfieldID fallDistanceField = NULL;
jfieldID onGroundField = NULL;

jclass C_Entity::GetClass()
{
	if (playerClass == NULL)
		playerClass = ct.env->FindClass("bew");

	return playerClass;
}

jobject C_Entity::GetInstance()
{
	if (getPlayerField == NULL)
		getPlayerField = ct.env->GetFieldID(C_Minecraft::GetClass(), "h", "Lbew;");

	if (playerObject == NULL)
		playerObject = ct.env->GetObjectField(C_Minecraft::GetInstance(), getPlayerField);

	return playerObject;
}

void C_Entity::SetSprinting(bool state)
{
	if (setSprintingMethod == NULL)
		setSprintingMethod = ct.env->GetMethodID(GetClass(), "d", "(Z)V");

	ct.env->CallBooleanMethod(GetInstance(), setSprintingMethod, state);
}

jdouble C_Entity::GetMotionX()
{
	if (motionXField == NULL)
		motionXField = ct.env->GetFieldID(GetClass(), "v", "D");

	return ct.env->GetDoubleField(GetInstance(), motionXField);
}

jdouble C_Entity::GetMotionY()
{
	if (motionYField == NULL)
		motionYField = ct.env->GetFieldID(GetClass(), "w", "D");

	return ct.env->GetDoubleField(GetInstance(), motionYField);
}

jdouble C_Entity::GetMotionZ()
{
	if (motionZField == NULL)
		motionZField = ct.env->GetFieldID(GetClass(), "x", "D");

	return ct.env->GetDoubleField(GetInstance(), motionZField);
}

void C_Entity::SetMotionX(jdouble value)
{
	ct.env->SetDoubleField(GetInstance(), motionXField, value);
}

void C_Entity::SetMotionY(jdouble value)
{
	ct.env->SetDoubleField(GetInstance(), motionYField, value);
}

void C_Entity::SetMotionZ(jdouble value)
{
	ct.env->SetDoubleField(GetInstance(), motionZField, value);
}

jint C_Entity::GetHurtResistantTime()
{
	if (hurtResistantTimeField == NULL)
		hurtResistantTimeField = ct.env->GetFieldID(GetClass(), "Z", "I");

	return ct.env->GetIntField(GetInstance(), hurtResistantTimeField);
}

jfloat C_Entity::GetFallDistance()
{
	if (fallDistanceField == NULL)
		fallDistanceField = ct.env->GetFieldID(GetClass(), "O", "F");

	return ct.env->GetFloatField(GetInstance(), fallDistanceField);
}

jboolean C_Entity::IsOnGround()
{
	if (onGroundField == NULL)
		onGroundField = ct.env->GetFieldID(GetClass(), "C", "B");

	return ct.env->GetBooleanField(GetInstance(), onGroundField);
}