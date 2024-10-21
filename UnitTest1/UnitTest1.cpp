#include "pch.h"
#include "CppUnitTest.h"
#include "../PR-7.1 IT/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int S = 0;
			int k = 0;
			int rC = 2;
			int cC = 2;
			int** a = new int* [rC];
			rowmem(a,rC,cC);
			a[0][0] = 1;
			a[0][1] = 3;
			a[1][0] = 6;
			a[1][1] = 5;
			Calc(a,2,3,S,k);
			Assert::AreEqual(S,9);
		}
	};
}
