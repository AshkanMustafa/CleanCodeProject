#pragma once
#include "Entity.h"
#include <string>

class NPC : public Entity {
public:
	NPC();
	NPC(const std::string&, const Point2D*);

	bool isAlive() const override;
};