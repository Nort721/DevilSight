#include "World.h"
#include "../client/Minecraft.h"

jclass worldClass = NULL;

jfieldID getWorldField = NULL;
jobject worldObject = NULL;

jclass C_World::getClass()
{
	if (worldClass == NULL)
		worldClass = ct.env->FindClass("bdb");

	return worldClass;
}

jobject C_World::getInstance()
{
	if (getWorldField == NULL)
		getWorldField = ct.env->GetFieldID(C_Minecraft::getClass(), "f", "Lbdb;");

	if (worldObject == NULL)
		worldObject = ct.env->GetObjectField(C_Minecraft::getInstance(), getWorldField);

	return worldObject;
}