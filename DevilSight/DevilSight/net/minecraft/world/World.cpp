#include "World.h"
#include "../client/Minecraft.h"

jclass worldClass = NULL;

jfieldID getWorldField = NULL;
jobject worldObject = NULL;

jclass C_World::GetClass()
{
	if (worldClass == NULL)
		worldClass = ct.env->FindClass("bdb");

	return worldClass;
}

jobject C_World::GetInstance()
{
	if (getWorldField == NULL)
		getWorldField = ct.env->GetFieldID(C_Minecraft::GetClass(), "f", "Lbdb;");

	if (worldObject == NULL)
		worldObject = ct.env->GetObjectField(C_Minecraft::GetInstance(), getWorldField);

	return worldObject;
}