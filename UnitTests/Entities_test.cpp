#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Domashno3/Player.cpp"
#include "../Domashno3/Entity.cpp"
#include "../Domashno3/Mob.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Player)
	{
	public:

		TEST_METHOD(attack)
		{
			::Point3D a, b(1, 1, 1);
			::Player p1("p1", &a, 12, 50), p2("p2", &b, 20, 44);
			p1.attack(&p2);
			Assert::AreEqual(32, p2.getHealth());
		}

		TEST_METHOD(moveTo)
		{
			::Point3D a, b(1, 1, 1);
			::Player p1("p1", &a, 12, 50), p2("p2", &b, 20, 44);
			p1.moveTo(p2);
			bool isMovingSuccessful = ((p1.getLocation()->getX() == p2.getLocation()->getX()) && (p1.getLocation()->getY() == p2.getLocation()->getY()));
			Assert::IsTrue(isMovingSuccessful);
		}

		TEST_METHOD(isAlive)
		{
			::Point3D a, b(1, 1, 1);
			::Player p1("p1", &a, 33, 50), p2("p2", &b, 20, 37);
			p1.attack(&p2);
			p1.attack(&p2);
			Assert::AreEqual(false, p2.isAlive());
		}

	};

	TEST_CLASS(Mob)
	{
	public:

		TEST_METHOD(attack)
		{
			::Point2D a, b(3, 3);
			::Player p1("p1", &a, 12, 30);
			::Mob m1("m1", &b, 20, 44);
			m1.attack(p1);
			Assert::AreEqual(10, p1.getHealth());
		}


		TEST_METHOD(moveTo)
		{
			::Point3D a, b(8, 4, 9);
			::Mob m1("m1", &a, 12, 50), m2("m2", &b, 20, 44);
			m1.moveTo(m2);
			bool isMovingSuccessful = ((m1.getLocation()->getX() == m2.getLocation()->getX()) && (m1.getLocation()->getY() == m2.getLocation()->getY()));
			Assert::IsTrue(isMovingSuccessful);
		}

		TEST_METHOD(isAlive)
		{
			::Point2D a, b(1, 1);
			::Player p1("p1", &a, 11, 30);
			::Mob m1("m1", &b, 30, 46);
			p1.attack(&m1);
			Assert::IsTrue(m1.isAlive());
		}
	};
}