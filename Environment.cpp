#include "Environment.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <float.h>

const unsigned int Environment::getSize() const
{
	return entities.size();
}

void Environment::addEntity(Entity* newEntity)
{
	entities.push_back(newEntity);
}

Entity* Environment::getEntityAt(const unsigned int index)
{
	if (index < this->getSize())
	{
		return entities[index];
	}
	else return nullptr;
}

void Environment::removeEntity(const unsigned int index)
{
	entities.erase(entities.begin() + index);
}

void Environment::generateEntities()
{
	Point2D* point1 = new Point2D(5, 5);
	Player* player1 = new Player("Stamatis", point1, 15, 75);
	this->addEntity(player1);

	Point2D* point2 = new Point3D(1, 9, 5);
	Mob* mob1 = new Mob("Floris", point2, 19, 91);
	this->addEntity(mob1);

	Point2D* point3 = new Point3D(4, 3, 6);
	Player* player2 = new Player("Itasis", point3, 33, 65);
	this->addEntity(player2);

	Point2D* point4 = new Point2D(9, 7);
	Mob* mob2 = new Mob("Olmifis", point4, 24, 96);
	this->addEntity(mob2);
}

void Environment::destroyEntities()
{
	entities.clear();
}

Entity & Environment::getClosestAliveEntity(Player& specificPlayer, EntityType specificType)
{
	double minDistance = DBL_MAX;
	unsigned int index = 0;

	for (int i = 0;  i < getSize(); ++i) {
		if (specificPlayer.getDistanceTo(*entities[i]) < minDistance && (*entities[i]).isAlive() == true
			&& (*entities[i]).getEntityType() == specificType && specificPlayer.getID() != (*entities[i]).getID()) {
			minDistance = specificPlayer.getDistanceTo(*entities[i]);
			index = i;
		}		
	}
	if (minDistance != DBL_MAX)
	{
		return (*entities[index]);
	}
}

void Environment::print() const
{
	std::cout << "Current entities in the Environment:\n";

	for (int i = 0; i < getSize(); ++i) 
	{
		(*entities[i]).print();
		std::cout << "\n\n\n";
	}
}
