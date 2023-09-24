#include "Minecraft.h"

jclass minecraftClass = NULL;

jobject minecraftObject = NULL;
jmethodID getMinecraftMethod = NULL;

jclass C_Minecraft::getClass()
{
	if (minecraftClass == NULL)
		minecraftClass = ct.env->FindClass("ave");

	return minecraftClass;
}

jobject C_Minecraft::getInstance()
{
	if (getMinecraftMethod == NULL)
		getMinecraftMethod = ct.env->GetStaticMethodID(getClass(), "A", "()Lave;");

	if (minecraftObject == NULL)
		minecraftObject = ct.env->CallStaticObjectMethod(getClass(), getMinecraftMethod);

	return minecraftObject;
}