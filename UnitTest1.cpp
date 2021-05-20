#include "pch.h"
#include "CppUnitTest.h"
#include "../OOPLab 5.1A/Goods.h"
#include "../OOPLab 5.1A/OOPLab 5.1A.cpp"
#include "../OOPLab 5.1A/Goods.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Goods a(27.2, 16);
			Assert::AreEqual(a.Cost(), 435.2);
		}
	};
}
