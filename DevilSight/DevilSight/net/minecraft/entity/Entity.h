#pragma once
#include "../../../Java.h"

class C_Entity
{
public:
	static jclass getClass();
	static jobject getInstance();

	static void setSprinting(bool state);

	static jdouble getMotionX();
	static jdouble getMotionY();
	static jdouble getMotionZ();

	static void setMotionX(jdouble value);
	static void setMotionY(jdouble value);
	static void setMotionZ(jdouble value);

	static jint getHurtResistantTime();
};