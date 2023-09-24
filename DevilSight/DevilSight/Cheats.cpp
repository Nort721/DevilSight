#include "Cheats.h"
#include "Java.h"

#include <thread>
#include <chrono>

#include <Windows.h>
#include "net/minecraft/client/Minecraft.h"
#include "net/minecraft/world/World.h"
#include "net/minecraft/entity/Entity.h"

void runModules()
{
	while (true) 
	{
		if (!C_Minecraft::GetInstance()) continue;
		if (!C_World::GetInstance()) continue;
		if (!C_Entity::GetInstance()) continue;

		sprintModule();
		velocityModule();
		autoclickerModule();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}