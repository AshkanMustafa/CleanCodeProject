#include "NPC.h"
#include <iostream>
#include <string>

NPC::NPC() : Entity()
{
	setEntityType(npc);
}

NPC::NPC(const std::string& newName, const Point2D* newLocation) : Entity(newName, newLocation)
{
	setEntityType(npc);
}

bool NPC::isAlive() const
{
	return true;
}
