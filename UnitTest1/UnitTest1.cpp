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
			Engine eng(120.5);
			Assert::AreEqual(120.5, eng.getPower());

			eng.setPower(130.0);
			Assert::AreEqual(130.0, eng.getPower());
		}
	};
}
