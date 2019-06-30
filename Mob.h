#pragma once
#include "Entity.h"
#include "Player.h"
#include <string>

class Mob : public Entity {
public:
	Mob();
	Mob(const std::string, const Point2D*, const int, const int);

	bool isAlive() const override;
	void print() const override;

	void attack(Player&); // Mob can attack only Player

	void setDamage(const int);
	void setHealth(const int);

	const int getDamage() const;
	const int getHealth() const;

private:
	int damage;
	int health;
};