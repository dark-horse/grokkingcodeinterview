#include "pch.h"
#include "CppUnitTest.h"
#include "..\linkedListReversal\reverseSubList.h"
#include "..\linkedListReversal\reverseKElementSublist.h"
#include "..\linkedListReversal\rotateLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsReverseLinkedList
{
    TEST_CLASS(reverseLinkedListTests)
    {
		TEST_METHOD(checkReverseSubList)
		{
			vector<tuple<vector<int>, int, int, vector<int>>> testcases =
			{
				{{1,2,3,4,5}, 2,4 ,{1,4,3,2,5}},
				{{1,2,3,4,5}, 2,5 ,{1,5,4,3,2}},
				{{1,2,3,4,5}, 1,4 ,{4,3,2,1,5}},
				{{1,2,3,4,5}, 1,5 ,{5,4,3,2,1}},
				{{1,2,3,4,5}, 1,3 ,{3,2,1,4,5}},
				{{1,2,3,4,5}, 0,2 ,{3,2,1,4,5}},
				{{1,2,3,4,5}, 0,4 ,{5,4,3,2,1}},
				{{1,2,3,4,5}, 2,8 ,{1,5,4,3,2}},
				{{1,2,3,4,5}, 1,8 ,{5,4,3,2,1}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto ll = reverseSubList::buildList(testcase);
				auto res = reverseSubList::reverse(ll, get<1>(testcases[i]), get<2>(testcases[i]));
				auto resLL = reverseSubList::buildList(get<3>(testcases[i]));
				Assert::IsTrue(reverseSubList::CompareLists(res,resLL));
			}
		}

		TEST_METHOD(checkReverseKElement)
		{
			vector<tuple<vector<int>, int, vector<int>>> testcases =
			{
				{{1,2,3,4,5,6,7,8}, 3 ,{3,2,1,6,5,4,8,7}},
				{{1,2,3,4,5,6,7,8}, 2 ,{2,1,4,3,6,5,8,7}},
				{{1,2,3,4,5,6,7,8}, 4 ,{4,3,2,1,8,7,6,5}},
				{{1,2,3,4,5,6,7,8}, 5 ,{5,4,3,2,1,8,7,6}},
				{{1,2,3,4,5,6,7,8}, 8 ,{8,7,6,5,4,3,2,1}},
				{{1,2,3,4,5,6,7,8}, 11 ,{8,7,6,5,4,3,2,1}},
				{{1,2}, 1 ,{1,2}},
				{{1,2}, 11 ,{2,1}},
				{{1,2}, 2 ,{2,1}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto ll = reverseKElementSublist::buildList(testcase);
				auto res = reverseKElementSublist::reverse(ll, get<1>(testcases[i]));
				auto resLL = reverseKElementSublist::buildList(get<2>(testcases[i]));
				Assert::IsTrue(reverseKElementSublist::CompareLists(res, resLL));
			}
		}

		TEST_METHOD(checkRotateList)
		{
			vector<tuple<vector<int>, int, vector<int>>> testcases =
			{
				{{1,2,3,4,5,6,7,8,9}, 5 ,{5,6,7,8,9,1,2,3,4}},
				{{1,2,3,4,5,6,7,8}, 3 ,{6,7,8,1,2,3,4,5}},
				{{1,2,3,4,5,6,7,8}, 1 ,{8,1,2,3,4,5,6,7}},
				{{1,2,3,4,5,6,7,8}, 2 ,{7,8,1,2,3,4,5,6}},
				{{1,2,3,4,5,6,7,8}, 5 ,{4,5,6,7,8,1,2,3}},
				{{1,2,3,4,5}, 8 ,{3,4,5,1,2}},
				{{1,2,3,4,5,6}, 6 ,{1,2,3,4,5,6}},
				{{1,2,3,4,5,6}, 37 ,{6,1,2,3,4,5}},
				{{1,2,3,4,5,6}, 7 ,{6,1,2,3,4,5}},
				{{1,2,3,4,5,6}, 8 ,{5,6,1,2,3,4}},
				{{1,2}, 1 ,{2,1}},
				{{1,2}, 2 ,{1,2}},
				{{1,2}, 3 ,{2,1}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto ll = rotateLinkedList::buildList(testcase);
				auto res = rotateLinkedList::rotate(ll, get<1>(testcases[i]));
				auto resLL = rotateLinkedList::buildList(get<2>(testcases[i]));
				Assert::IsTrue(rotateLinkedList::CompareLists(res, resLL));
			}
		}
	};
}