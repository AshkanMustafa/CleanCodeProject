#include "Entity.h"
#include <iostream>
#include <cmath>
#include <string>

unsigned int Entity::nextID = 0; // initializing the static class-member which helps generating id's

Entity::Entity() : id(++nextID), name("An unnamed entity")
{
	location = new Point2D(); // default location is 2-dimensional space
}

Entity::Entity(std::string newName, const Point2D* newLocation) : id(++nextID), name(newName)
{
	this->location = newLocation->clone();
}

Entity::Entity(const Entity & rhs) : id(rhs.id), name(rhs.name)
{
	this->location = (rhs.location)->clone();
}

Entity & Entity::operator=(const Entity & rhs)
{
	if (this != &rhs)
	{
		this->id = rhs.id;
		this->name = rhs.name;

		delete location;
		this->location = (rhs.location)->clone();
	}
	return *this;
}

Entity::~Entity()
{
	delete this->location;
}

const EntityType Entity::getEntityType() const
{
	return this->type;
}

const unsigned int Entity::getID() const
{
	return this->id;
}

const std::string & Entity::getName() const
{
	return this->name;
}

Point2D * Entity::getLocation() const
{
	return this->location;
}

void Entity::setEntityType(const EntityType newType)
{
	this->type = newType;
}

void Entity::setName(const std::string& newName)
{
	this->name = newName;
}

void Entity::moveTo(const Point2D * newLocation)
{
	delete this->location;
	this->location = (newLocation)->clone();
}

void Entity::moveTo(const Entity & entity)
{
	delete location;
	this->location = entity.location->clone();
}

const double Entity::getDistanceToIn2D(const Entity& entity)
{
	return this->location->getDistanceTo(*(entity.location));
}

const double Entity::getDistanceTo(const Entity& entity)
{
	// if both locations are in 3rd dimension
	if ((this->location)->isPoint2D() == false && (entity.location)->isPoint2D() == false)
	{
		Point3D* first = dynamic_cast<Point3D*> ((this->location));
		Point3D* second = dynamic_cast<Point3D*> ((entity.location));

		return (*first).getDistanceTo(*second);
	}
	// in any other case, we treat it all as 2nd dimension
	return this->location->getDistanceTo(*(entity.location));
}

bool Entity::isAlive() const
{
	return true;
}

void Entity::print() const
{
	std::cout << "    Type: " << getEntityType() << std::endl
		<< "      ID: " << getID() << std::endl
		<< "    Name: " << getName() << std::endl;

		if (getLocation()->isPoint2D() == false) 
		{
			Point3D& place = dynamic_cast<Point3D&> (*(this->location));

			std::cout << "Location: (" << place.getX() << ", " <<
				place.getY() << ", " << place.getZ() << ")\n";
		}
		else 
		{
			std::cout << "Location: (" << getLocation()->getX() << ", " <<
				getLocation()->getY() << ")\n";
		}
}

