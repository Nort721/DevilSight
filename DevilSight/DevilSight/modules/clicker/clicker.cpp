#include "clicker.h"
#include <Windows.h>
#include <iostream>
#include <random>
#include "../../net/minecraft/client/Minecraft.h"

void autoclickerModule()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		C_Minecraft::LeftClick();
	}
}