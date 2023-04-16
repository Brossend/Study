#include "pch.h"
#include "CppUnitTest.h"
#include "../unit-test 1_2/example.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest12
{
	TEST_CLASS(UnitTest12)
	{
	public:

		TEST_METHOD(Check1)
		{
			example A1(0);
			A1.residue();
			A1.print();
			Assert::IsTrue(A1.Get_result() == 0, L"Assert 1, Check 1");

			Logger::WriteMessage("���� Check 1 �������� �������!");
		}
		TEST_METHOD(Check2)
		{
			example A1(1);
			A1.residue();
			A1.print();
			Assert::IsTrue(A1.Get_result() == 1, L"Assert 1, Check 2");

			Logger::WriteMessage("���� Check 2 �������� �������!");
		}
		TEST_METHOD(Check3)
		{
			example A1(2);
			A1.residue();
			A1.print();
			Assert::IsTrue(A1.Get_result() == 2, L"Assert 1, Check 3");

			Logger::WriteMessage("���� Check 3 �������� �������!");
		}
		TEST_METHOD(Check4)
		{
			example A1(3);
			A1.residue();
			A1.print();
			Assert::IsTrue(A1.Get_result() == 3, L"Assert 1, Check 4");

			Logger::WriteMessage("���� Check 4 �������� �������!");
		}
		TEST_METHOD(Check5)
		{
			example A1(4);
			A1.residue();
			A1.print();
			Assert::IsTrue(A1.Get_result() == 4, L"Assert 1, Check 5");

			Logger::WriteMessage("���� Check 5 �������� �������!");
		}
	};
}
