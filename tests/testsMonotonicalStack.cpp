#include "pch.h"
#include "CppUnitTest.h"
#include "..\monotonicalStack\dailyTemperatures.h"
#include "..\monotonicalStack\removeNodesFromLinkedList.h"
#include "..\monotonicalStack\removeAdjacentCharacters.h"
#include "..\monotonicalStack\remAdjChars2.h"
#include "..\monotonicalStack\remKDigits.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsMonotonicalStack
{
    TEST_CLASS(monotonicalStackTests)
    {
		TEST_METHOD(checkDailyTemperatures)
		{
			vector<tuple<vector<int>, vector<int>>> testcases =
			{
				{{70, 73, 75, 71, 69, 72, 76, 73} , {1, 1, 4, 2, 1, 1, 0, 0}},
				{{70, 73, 75, 71, 69, 72, 74, 73} , {1, 1, 0, 2, 1, 1, 0, 0}},
				{{73, 72, 71, 70},{0, 0, 0, 0}},
				{{70, 71, 72, 73},{1, 1, 1, 0}},
				{{6},{0}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = dailyTemperaturesClass::dailyTemperatures(testcase);
				Assert::IsTrue(res == get<1>(testcases[i]));
				res = dailyTemperaturesClass::dailyTemperaturesFast(testcase);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkRemoveNodesFromLinkedList)
		{
			vector<tuple<vector<int>, vector<int>>> testcases =
			{
				{{5,3, 7, 4 ,2 ,1} , {7,4 ,2 ,1}},
				{{1,2,3,4,5} , {5}},
				{{5,4,3,2,1},{5,4,3,2,1}},
				{{5} , {5}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto input = removeNodesFromLinkedList::buildList(testcase);
				auto res = removeNodesFromLinkedList::removeNodes(input);
				auto expect = removeNodesFromLinkedList::buildList(get<1>(testcases[i]));
				Assert::IsTrue(removeNodesFromLinkedList::CompareLists(res, expect));
			}
		}

		TEST_METHOD(checkRemoveAdjacentCharacters)
		{
			vector<tuple<string, string>> testcases =
			{
				{"abccba", ""},
				{"foobar", "fbar"},
				{"fooobar", "fobar"},
				{"abcd", "abcd"},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				Assert::IsTrue(get<1>(testcases[i]) == remAdjChars::removeDuplicates(testcase));
			}
		}

		TEST_METHOD(checkRemoveAdjacentCharacters2)
		{
			vector<tuple<string, int, string>> testcases =
			{
				{"aaaa", 2, ""},
				{"baab", 2, ""},
				{"aaaa", 4, ""},
				{"abccba", 2, ""},
				{"foobar", 2, "fbar"},
				{"fooobar", 2, "fobar"},
				{"abcd", 2, "abcd"},
				{"abbbaaca", 3, "ca"},
				{"abbacccaa", 3, "abb"},
				{"abbaccaa", 3, "abbaccaa"},
				{"abbacccaa", 3, "abb"},
				{"abbacccaa", 1, ""},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				Assert::IsTrue(get<2>(testcases[i]) == remAdjChars2::removeDuplicates(testcase, get<1>(testcases[i])));
			}
		}

		TEST_METHOD(checkRemoveKDigits)
		{
			vector<tuple<string, int, string>> testcases =
			{
				{"1223", 2, "12"},
				{"1234", 2, "12"},
				{"1231", 2, "11"},
				{"1432219", 3, "1219"},
				{"10200", 1, "200"},
				{"10200", 2, "0"},
				{"1901042", 4, "2"},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				Assert::IsTrue(get<2>(testcases[i]) == remKDigits::removeKdigits(testcase, get<1>(testcases[i])));
			}
		}
	};
}