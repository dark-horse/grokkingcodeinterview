#include "pch.h"
#include "CppUnitTest.h"
#include "..\cyclicSort\missingNumbers.h"
#include "..\cyclicSort\duplicateNumber.h"
#include "..\cyclicSort\kMissingIntegers.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsCyclicSort
{
    TEST_CLASS(missingNumbersTests)
    {
        TEST_METHOD(checkMissingNumbers)
        {
			vector<tuple<vector<int>, vector<int>>> testcases =
			{
				{{2, 3, 1, 8, 2, 3, 5, 1},{4, 6, 7}},
				{{2, 4, 1, 2},{3}},
				{{2, 3, 2, 1},{4}},
				{{6,6,1,1,2,2,3},{4,5,7}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = missingNumbers::findNumbers(testcase);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
        }

		TEST_METHOD(checkDuplicateNumbers)
		{
			vector<tuple<vector<int>, int>> testcases =
			{
				{{2, 3, 1, 8, 2, 4, 5, 6},2},
				{{2, 3, 1, 8, 2, 2, 5, 6},2},
				{{1, 4, 4, 3, 2},4},
				{{2, 1, 3, 3, 5, 4},3},
				{{2, 4, 1, 4, 4},4},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = duplicateNumber::findNumber(testcase);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkKMissingIntegers)
		{
			vector<tuple<vector<int>, int, vector<int>>> testcases =
			{
				{{-3, 1, 5, 4, 2}, 1,{3}},
				{{3, -2, 0, 1, 2}, 1,{4}},
				{{3, 2, 5, 1}, 1,{4}},
				{{33, 37, 5}, 1,{1}},
				{{3, -1, 4, 5, 5}, 3,{1,2,6}},
				{{2, 3, 4}, 3,{1,5,6}},
				{{3, 4, 5}, 3,{1,2,6}},
				{{1, 3, 4}, 6,{2,5,6,7,8,9}},
				{{1, 3, 5}, 6,{2,4,6,7,8,9}},
				{{-2, -3, 4}, 2,{1,2}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = kMissingIntegers::findNumbers(testcase, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}
	};
}