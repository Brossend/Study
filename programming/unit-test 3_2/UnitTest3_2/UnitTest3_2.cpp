#include "pch.h"
#include "CppUnitTest.h"
#include "..\unit-test 3_2\var.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest32
{
	TEST_CLASS(UnitTest32)
	{
	public:

		TEST_METHOD(check)
		{
			float X_test = 0.314159274, F1_test = 5, F2_test = 1.41421354;

			var A(20);

			A.metod();

			Assert::IsTrue(A.Get_seq(1) == X_test, L"Assert 1");
			Assert::IsTrue(A.Get_seq1(5) == F1_test, L"Assert 2");
			Assert::IsTrue(A.Get_seq2(5) == F2_test, L"Assert 3");

			Logger::WriteMessage("Тесты завершены успешно!");
		}
	};
}
