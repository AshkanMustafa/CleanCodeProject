#pragma once
#include "Entity.h"
#include <string>

class Player : public Entity {
public:
	Player();
	Player(std::string, const Point2D*, const int, const int);

	virtual bool isAlive() const override;
	virtual void print() const override;

	void attack(Entity*); // Entity* can be a different Player or Mob

	void setDamage(const int);
	void setHealth(const int);

	const int getDamage() const;
	const int getHealth() const;

private:
	int damage;
	int health;
};