#include <iostream>
#include "Player.h"
#include "Mob.h"
#include "NPC.h"
#include "Environment.h"

int main()
{
	Point3D a, b(1, 1, 1);
	Player p1("p1", &a, 12, 50), p2("p2", &b, 20, 44);

	std::cout << "Distance from p1(0,0,0) to p2(1,1,1): ";
	std::cout << p1.getDistanceTo(p2) << std::endl << std::endl;
	std::cout << "Distance from p1(0,0,0) to p2(1,1,1) treated in 2nd dimension: ";
	std::cout << p1.getDistanceToIn2D(p2) << std::endl << std::endl;

	Point3D f(2, 2, 2);
	p2.moveTo(&f);
	std::cout << "Location of p2(1,1,1) was changed to p2(2,2,2). New distance from p1(0,0,0) to p2(2,2,2): ";
	std::cout << p1.getDistanceTo(p2) << std::endl << std::endl;

	Point2D d, e(3, 3);
	Player p3("p3", &e, 16, 49);

	p2.moveTo(p3);
	std::cout << "Location of p2(1,1,1) was changed to p2(3, 3). New distance from p1(0,0,0) to p2(3, 3): ";
	std::cout << p1.getDistanceTo(p2) << std::endl << std::endl;

	std::cout << "			   Health of p3: " << p3.getHealth() << std::endl;
	p1.attack(&p3);
	std::cout << "Health of p3 after being attacked by p1: " << p3.getHealth() << std::endl << std::endl;

	Player goodPlayer("player1", &d, 10, 48);

	Environment currentEnvironment;
	currentEnvironment.addEntity(&goodPlayer);
	currentEnvironment.generateEntities();

	std::cout << "Closest entity to goodPlayer:\n\n";
	currentEnvironment.getClosestAliveEntity(goodPlayer, player).print();
	std::cout << std::endl;

}