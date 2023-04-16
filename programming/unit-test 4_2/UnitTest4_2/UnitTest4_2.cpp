#include "pch.h"
#include "CppUnitTest.h"
#include "..\unit-test 4_2\fooABC.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest42
{
	TEST_CLASS(UnitTest42)
	{
	public:

		TEST_METHOD(check)
		{
			fooABC A;

			Assert::IsTrue(A.FooABC() == 13, L"Assert 1");

			Logger::WriteMessage("Тест завершен успешно!");
		}
	};
}
