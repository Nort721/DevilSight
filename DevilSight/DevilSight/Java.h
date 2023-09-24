#pragma once
#include "JNI//jni.h"

class cheat 
{
public:
	JavaVM* vm;
	JNIEnv* env;

	JavaVMInitArgs args;
}ct;