#pragma once
#include "Point2D.h"
#include "Point3D.h"
#include <string>

// used as a parameter for the types related to polymorphic entities
enum EntityType { player, npc, mob };

class Entity {
public:
	Entity();
	Entity(std::string, const Point2D*);
	Entity(const Entity&);
	Entity& operator=(const Entity&);
	virtual ~Entity();

	const EntityType getEntityType() const;
	const unsigned int getID() const;
	const std::string& getName() const;
	Point2D* getLocation() const;

	void setEntityType(const EntityType);
	void setName(const std::string&);

	virtual bool isAlive() const;
	virtual void print() const;

	const double getDistanceToIn2D(const Entity&); // location is always treated as Point2D (requirement)
	const double getDistanceTo(const Entity&);	 // location can be either Point2D or Point3D
	void moveTo(const Point2D*); // changes the location of the current object to the new specified location
	void moveTo(const Entity&);  // changes the location of the current object to the same location as the given entity

protected:
	unsigned int id;
	std::string name;
	Point2D* location;
	EntityType type;

	static unsigned int nextID; // helps generating id's
};