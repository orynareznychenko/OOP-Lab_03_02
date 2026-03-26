#include "pch.h"
#include "CppUnitTest.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.2/Car.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.2/Engine.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.2/Lorry.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double validPower = 150.5;
			Engine eng(validPower);
			Assert::AreEqual(validPower, eng.getPower());
		}
	};
}
