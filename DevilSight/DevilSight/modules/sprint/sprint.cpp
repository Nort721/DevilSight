#include "sprint.h"
#include <Windows.h>
#include "../../net/minecraft/entity/Entity.h"

void sprintModule()
{
	// only sprint if player is going in a valid direction
	if (!GetAsyncKeyState('W') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_LCONTROL)) return;

	C_Entity::setSprinting(true);
}
