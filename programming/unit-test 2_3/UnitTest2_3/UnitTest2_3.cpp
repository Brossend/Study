#include "pch.h"
#include "CppUnitTest.h"
#include "../unit-test 2_3/while_do.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest23
{
	TEST_CLASS(UnitTest23)
	{
	public:

		TEST_METHOD(Test_0_5)
		{
			float Test_1 = 1.4142135623730951, Test_2 = 745.23958062608904;

			while_do A(0.5);

			A.whilef();

			Assert::IsTrue(A.Get_Z1() == Test_1, L"Assert 1, Test_0_5");
			Assert::IsTrue(A.Get_Z2() == Test_2, L"Assert 2, Test_0_5");

			Logger::WriteMessage("Тест Test_0_5 выполнен успешно!");
		}
		TEST_METHOD(Test_1_0)
		{
			float Test_1 = 1.8371173070873836, Test_2 = 27.308232836016487;

			while_do A(1);

			A.whilef();

			Assert::IsTrue(A.Get_Z1() == Test_1, L"Assert 1, Test_1_0");
			Assert::IsTrue(A.Get_Z2() == Test_2, L"Assert 2, Test_1_0");

			Logger::WriteMessage("Тест Test_1_0 выполнен успешно!");
		}
	};
}