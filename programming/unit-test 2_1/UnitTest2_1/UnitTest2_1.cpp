#include "pch.h"
#include "CppUnitTest.h"
#include "..\unit-test 2_1\repeat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest21
{
	TEST_CLASS(UnitTest21)
	{
	public:
		
		TEST_METHOD(repeat_1)
		{
			float F1_Test = 5, F2_Test = 1.41421354, X_Test = 0.314159274;

			repeat A(20);
			A.do_while();

			Assert::IsTrue(A.Get_F1_Test() == F1_Test, L"Assert 1, repeat_1");
			Assert::IsTrue(A.Get_F2_Test() == F2_Test, L"Assert 2, repeat_1");
			Assert::IsTrue(A.Get_X() == X_Test, L"Assert 3, repeat_1");

			Logger::WriteMessage("Тест завершен repeat_1 завершен успешно!");
		}
	};
}
