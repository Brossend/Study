#include "pch.h"
#include "CppUnitTest.h"
#include "../unit-test 3_1 inc/var.h"
#include "../unit-test 3_1 dec/varrr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest31
{
	TEST_CLASS(UnitTest31)
	{
	public:

		TEST_METHOD(inc)
		{
			var A;

			A.check();

			Assert::IsTrue(A.Get_TF() == false, L"Assert 1, inc");

			Logger::WriteMessage("Тест пройден успешно!");
		}

		TEST_METHOD(dec)
		{
			varrr A;

			A.metod();

			Assert::IsTrue(A.Get_TF() == true, L"Assert 1, dec");

			Logger::WriteMessage("Тест пройден успешно!");
		}
	};
}
