#include "ForgeUtil.h"

bool ForgeUtil::AlreadyCheckedForge = false;
bool ForgeUtil::IsForgeExisting = false;

jclass ForgeUtil::ForgeFindClass(const char* name)
{
	if (LaunchWrapperClassLoaderClass == NULL)
	{
		LaunchWrapperClassLoaderClass = ct.env->FindClass("net/minecraft/launchwrapper/LaunchClassLoader");
		if (LaunchWrapperClassLoaderClass == NULL) return NULL;
	}

	if (FindClassMethodID == NULL)
	{
		FindClassMethodID = ct.env->GetMethodID(LaunchWrapperClassLoaderClass, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
		if (FindClassMethodID == NULL) return NULL;
	}

	if (LaunchClass == NULL)
	{
		LaunchClass = ct.env->FindClass("net/minecraft/launchwrapper/Launch");
		if (LaunchClass == NULL) return NULL;
	}

	if (ClassLoaderFieldID == NULL)
	{
		ClassLoaderFieldID = ct.env->GetStaticFieldID(LaunchClass, "classLoader", "Lnet/minecraft/launchwrapper/LaunchClassLoader;");
		if (ClassLoaderFieldID == NULL) return NULL;
	}

	if (ClassLoaderObject == NULL)
	{
		ClassLoaderObject = ct.env->GetStaticObjectField(LaunchClass, ClassLoaderFieldID);
		if (ClassLoaderObject == NULL) return NULL;
	}

	jstring jname = ct.env->NewStringUTF(name);
	jclass cls = (jclass)ct.env->CallObjectMethod(ClassLoaderObject, FindClassMethodID, jname);

	ct.env->DeleteLocalRef(jname);

	return cls;
}

bool ForgeUtil::IsForge()
{
	if (!AlreadyCheckedForge)
	{
		AlreadyCheckedForge = true;
		jclass forgeClass = ct.env->FindClass("net/minecraftforge/common/ForgeVersion");
		if (forgeClass != NULL)
		{
			ct.env->DeleteLocalRef(forgeClass);
			IsForgeExisting = true;
		}
	}
	return IsForgeExisting;
}