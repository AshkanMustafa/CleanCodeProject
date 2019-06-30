#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project/Point3D.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Point3D)
	{
	public:

		TEST_METHOD(getDistanceTo)
		{
			::Point3D a, b(3, 3, 3);
			Assert::AreEqual(sqrt(27), a.getDistanceTo(b));
		}

	};
}
