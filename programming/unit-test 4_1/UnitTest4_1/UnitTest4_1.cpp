#include "pch.h"
#include "CppUnitTest.h"
#include "..\unit-test 4_1\first.h"
#include "..\unit-test 4_1\sixth.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest41
{
	TEST_CLASS(UnitTest41)
	{
	public:

		TEST_METHOD(first_check)
		{
			float x1 = 0.165606424, x2 = 0.0784225166;

			first A;

			A.Set_x1(1);
			A.Set_x2(2);

			Assert::IsTrue(A.ex1_x1() == x1, L"Assert 1");
			Assert::IsTrue(A.ex1_x2() == x2, L"Assert 2");

			Logger::WriteMessage("Тест first_check завершен успешно!");
		}
		TEST_METHOD(sixth_check)
		{
			float* seq_test1 = new float[5]{ 1.23,3.56,5.78,8.54,9.43 };
			float* seq_test2 = new float[5]{ 1.23,0,5.78,8.54,9.43 };

			sixth A;

			Assert::IsTrue(A.ex6_1(5, seq_test1) == false, L"Assert 1, inc");
			Assert::IsTrue(A.ex6_1(5, seq_test2) == true, L"Assert 1, dec");

			Logger::WriteMessage("Тест sixth_check завершен успешно!");
		}
	};
}
