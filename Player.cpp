#include "Player.h"
#include "Mob.h"
#include <iostream>
#include <cmath>
#include <string> 

Player::Player() : Entity(), damage(0), health(0)
{
	setEntityType(player);
}

Player::Player(std::string newName, const Point2D * newLocation, const int newDamage, const int newHealth)
	: Entity(newName, newLocation), damage(newDamage), health(newHealth)
{
	setEntityType(player);
}

bool Player::isAlive() const
{
	if (this->getHealth() > 0)
	{
		return true;
	}
	return false;
}

void Player::print() const
{
	Entity::print();
	std::cout << "  Damage: " << this->getDamage() << std::endl << "  Health: " << this->getHealth() << std::endl;
}

void Player::attack(Entity* playerOrMob)
{
	if (dynamic_cast<Player*>(playerOrMob) != nullptr) 
	{
		Player* other = dynamic_cast<Player*>(playerOrMob);
		double distance = this->getDistanceTo(*other);
		if (distance < 5 && (*other).isAlive() == true)
		{
			(*other).setHealth((*other).getHealth() - this->getDamage());
		}
		else
		{
			std::cout << "The player you are trying to attack is either too far away or dead\n";
		}
	}
	else if(dynamic_cast<Mob*>(playerOrMob) != nullptr)
	{
		Mob* other = dynamic_cast<Mob*>(playerOrMob);
		double distance = this->getDistanceTo(*other);
		if (distance < 5 && (*other).isAlive() == true)
		{
			(*other).setHealth((*other).getHealth() - this->getDamage());
		}
		else
		{
			std::cout << "The mob you are trying to attack is either too far away or dead\n";
		}
	}
	else 
	{
		std::cout << "You cannot attack NPC!\n";
	}
}

void Player::setDamage(const int newDamage)
{
	this->damage = newDamage;
}

void Player::setHealth(const int newHealth)
{
	this->health = newHealth;
}

const int Player::getDamage() const
{
	return this->damage;
}

const int Player::getHealth() const
{
	return this->health;
}
