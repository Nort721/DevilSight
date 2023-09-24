#pragma once
#include "../../../Java.h"

class C_Entity
{
public:
	static jclass GetClass();
	static jobject GetInstance();

	static void SetSprinting(bool state);

	static jdouble GetMotionX();
	static jdouble GetMotionY();
	static jdouble GetMotionZ();

	static void SetMotionX(jdouble value);
	static void SetMotionY(jdouble value);
	static void SetMotionZ(jdouble value);

	static jint GetHurtResistantTime();
	static jfloat GetFallDistance();
	static jboolean IsOnGround();
};