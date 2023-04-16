#include "pch.h"
#include "CppUnitTest.h"
#include "../unit-test 2_2/que.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest22
{
	TEST_CLASS(UnitTest22)
	{
	public:

		TEST_METHOD(Test_1)
		{
			float test = 4;
			que A;
			A.queque();

			Assert::IsTrue(A.Get_result() == test, L"Assert 1, Test_1");

			Logger::WriteMessage("Тестирование Test_1 завершено успешно!");
		}
	};
}