#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project/Point2D.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(Point2D)
	{
	public:
		
		TEST_METHOD(getDistanceTo)
		{
			::Point2D a, b(1, 1);
			Assert::AreEqual(sqrt(2), a.getDistanceTo(b));
		}

	};
}
