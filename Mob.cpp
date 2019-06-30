#include "Mob.h"
#include <iostream>
#include <cmath>
#include <string>

Mob::Mob() : Entity(), damage(0), health(0)
{
	setEntityType(mob);
}

Mob::Mob(const std::string newName, const Point2D* newLocation, const int newDamage, const int newHealth)
	: Entity(newName, newLocation), damage(newDamage), health(newHealth)
{
	setEntityType(mob);
}

bool Mob::isAlive() const
{
	if (this->getHealth() > 0)
	{
		return true;
	}
	return false;
}

void Mob::print() const
{
	Entity::print();
	std::cout << "  Damage: " << this->getDamage() << std::endl << "  Health: " << this->getHealth() << std::endl;
}

void Mob::attack(Player& rhs)
{
	double distance = this->getDistanceTo(rhs);
	if (distance < 5 && rhs.isAlive() == true)
	{
		rhs.setHealth(rhs.getHealth() - this->getDamage());
	}
	else
	{
		std::cout << "The player you are trying to attack is either too far away or dead\n";
	}
}

void Mob::setDamage(const int newDamage)
{
	this->damage = newDamage;
}

void Mob::setHealth(const int newHealth)
{
	this->health = newHealth;
}

const int Mob::getDamage() const
{
	return this->damage;
}

const int Mob::getHealth() const
{
	return this->health;
}
