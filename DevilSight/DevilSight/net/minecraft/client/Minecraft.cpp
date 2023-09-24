#include "Minecraft.h"

jclass minecraftClass = NULL;

jobject minecraftObject = NULL;
jmethodID getMinecraftMethod = NULL;

jmethodID leftClickMethodID = NULL;

jclass C_Minecraft::GetClass()
{
	if (minecraftClass == NULL)
		minecraftClass = ct.env->FindClass("ave");

	return minecraftClass;
}

jobject C_Minecraft::GetInstance()
{
	if (getMinecraftMethod == NULL)
		getMinecraftMethod = ct.env->GetStaticMethodID(GetClass(), "A", "()Lave;");

	if (minecraftObject == NULL)
		minecraftObject = ct.env->CallStaticObjectMethod(GetClass(), getMinecraftMethod);

	return minecraftObject;
}

void C_Minecraft::LeftClick()
{
	if (GetClass() == NULL) return;

	if (leftClickMethodID == NULL)
	{
		leftClickMethodID = ct.env->GetMethodID(GetClass(), "aw", "()V");
		if (leftClickMethodID == NULL) return;
	}

	ct.env->CallVoidMethod(GetInstance(), leftClickMethodID);
}