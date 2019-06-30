#pragma once
#include "Entity.h"
#include "Mob.h"
#include "NPC.h"
#include "Player.h"
#include <vector>

class Environment {
public:
	const unsigned int getSize() const;

	void addEntity(Entity*);
	Entity* getEntityAt(const unsigned int index);
	void removeEntity(const unsigned int index);
	void generateEntities(); // creates several entities of different type
	void destroyEntities();	 // clears up all entities
	Entity& getClosestAliveEntity(Player&, EntityType); // returns the closest entity to the specified player who has the specified type

	void print() const;

private:
	std::vector <Entity*> entities;
};