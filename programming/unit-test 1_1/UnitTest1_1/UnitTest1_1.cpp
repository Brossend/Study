#include "pch.h"
#include "CppUnitTest.h"
#include "../unit-test 1_1/Example.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest11
{
	TEST_CLASS(UnitTest11)
	{
	public:
		
		TEST_METHOD(Check1)
		{
			float A = -5.2;
			Example A1(3);
			A1.check();
			Assert::IsTrue(A1.Get_Z() == A, L"Assert 1 Check 1");

			Logger::WriteMessage(L"Тест Check1 завершен успешно!");
		}
		TEST_METHOD(Check2)
		{
			float A = 2.46766877;
			Example A1(11);
			A1.check();
			Assert::IsTrue(A1.Get_Z() == A, L"Assert 1 Check 2");

			Logger::WriteMessage(L"Тест Check2 завершен успешно!");
		}
		TEST_METHOD(Check3)
		{
			float A = -7.89238834;
			Example A1(1);
			A1.check();
			Assert::IsTrue(A1.Get_Z() == A, L"Assert 1 Check 3");

			Logger::WriteMessage(L"Тест Check3 завершен успешно!");
		}
	};
}
