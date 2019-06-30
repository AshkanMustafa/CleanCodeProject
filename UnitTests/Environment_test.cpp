#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Domashno3/Environment.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Environment)
	{
	public:

		TEST_METHOD(addEntity)
		{
			::Point2D d(5, 7);
			::Player currentPlayer("player1", &d, 10, 48);
			::Environment currentEnvironment;
			currentEnvironment.addEntity(&currentPlayer);
			bool isAddingSuccessful = (currentEnvironment.getSize() > 0);
			Assert::IsTrue(isAddingSuccessful);
		}
		TEST_METHOD(removeEntity)
		{
			::Point2D d(5, 7);
			::Player currentPlayer("player1", &d, 10, 48);
			::Environment currentEnvironment;
			currentEnvironment.addEntity(&currentPlayer);
			currentEnvironment.removeEntity(0);
			bool isRemovingSuccessful = (currentEnvironment.getSize() == 0);
			Assert::IsTrue(isRemovingSuccessful);
		}
		TEST_METHOD(destroyEntities)
		{
			::Point2D d(5, 7), b(31, 9);
			::Player currentPlayer("player1", &d, 10, 48);
			::Mob currentMob("m1", &b, 20, 44);
			::Environment currentEnvironment;
			currentEnvironment.addEntity(&currentPlayer);
			currentEnvironment.addEntity(&currentMob);
			currentEnvironment.destroyEntities();
			bool isDestroyingSuccessful = (currentEnvironment.getSize() == 0);
			Assert::IsTrue(isDestroyingSuccessful);
		}
	};
}