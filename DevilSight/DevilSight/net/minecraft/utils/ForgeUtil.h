#pragma once
#include "../../../Java.h"

class ForgeUtil
{
private:
	inline static jclass LaunchWrapperClassLoaderClass;
	inline static jmethodID FindClassMethodID;
	inline static jclass LaunchClass;
	inline static jfieldID ClassLoaderFieldID;
	inline static jobject ClassLoaderObject;

	static bool AlreadyCheckedForge;
	static bool IsForgeExisting;

public:
	inline static JNIEnv* env;
	static jclass ForgeFindClass(const char*);
	static bool IsForge();
};