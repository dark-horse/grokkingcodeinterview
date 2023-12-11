
#include "pch.h"
#include "CppUnitTest.h"
#include "..\fastSlowPointers\linkedListCycle.h"	// What a piece of @#!*&&&@.  Only after including this file we can build with <vector> anything....
#include "..\fastSlowPointers\happyNumber.h"
#include "..\fastSlowPointers\palindromeLinkedList.h"
#include "..\fastSlowPointers\rearrangeLinkedList.h"
#include "..\fastSlowPointers\cycleCircularArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fastSlowPointer
{
    TEST_CLASS(fastSlowPointersTests)
    {
    public:
		TEST_METHOD(checkHappyNumber)
		{
			vector<tuple<int, bool>> testcases =
			{
				{23, true},
				{12, false},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = happyNumber::find(testcase);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkPalindrome)
		{
			vector<tuple<vector<int>, bool>> testcases =
			{
				{{23}, true},
				{{1,2,3,4}, false},
				{{1,2,3,4,5}, false},
				{{1,2,3,4,5,6}, false},
				{{1,2,3,4,5,6,7}, false},
				{{1,2,3,4,5,6,7,8}, false},
				{{1,2,2,1}, true},
				{{1,2,3,2,1}, true},
				{{1,2,3,3,2,1}, true},
				{{1,2,3,4,3,2,1}, true},
				{{1,2,3,4,4,3,2,1}, true},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto linkedList = palindromeLinkedList::buildListFromVector(testcase);
				auto res = palindromeLinkedList::isPalindrome(linkedList);
				Assert::IsTrue(res == get<1>(testcases[i]));
				// check that the linked list is not changed
				auto curr = linkedList;
				for (int i = 0; i < testcase.size(); i++)
				{
					Assert::IsTrue(curr != nullptr && testcase[i] == curr->val);
					curr = curr->next;
				}
				Assert::IsTrue(curr == nullptr);
			}
		}

		TEST_METHOD(checkRearrangeLinkedList)
		{
			vector<tuple<vector<int>, vector<int>>> testcases =
			{
				{{23}, {23}},
				{{1,2}, {1,2}},
				{{1,2,3}, {1,3,2}},
				{{1,2,3,4}, {1,4,2,3}},
				{{1,2,3,4,5}, {1,5,2,4,3}},
				{{1,2,3,4,5,6}, {1,6,2,5,3,4}},
				{{1,2,3,4,5,6,7}, {1,7,2,6,3,5,4}},
				{{1,2,3,4,5,6,7,8}, {1,8,2,7,3,6,4,5}},
				{{1,2,3,4,5,6,7,8,9}, {1,9,2,8,3,7,4,6,5}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto linkedList = rearrangeLinkedList::buildListFromVector(testcase);
				auto res = rearrangeLinkedList::reorder(linkedList);
				// check that the linked list matches the output
				auto expectedOutput = get<1>(testcases[i]);
				auto curr = linkedList;
				for (int i = 0; i < expectedOutput.size(); i++)
				{
					Assert::IsTrue(curr != nullptr && expectedOutput[i] == curr->val);
					curr = curr->next;
				}
				Assert::IsTrue(curr == nullptr);
			}
		}

		TEST_METHOD(checkcycleCircularArray)
		{
			vector<tuple<vector<int>, bool>> testcases =
			{
				{{23}, false},
				{{1,2,3,4}, false},
				{{1, 2, -1, 2, 2}, true},
				{{2, 2, -1, 2}, true},
				{{2, 1, -1, -2}, false},
				{{1,2,3,4,5,6,7,8}, false},
				{{1,2,3,4,5,6,7,1}, true},
				{{-1,2,3,4,5,6,7,1}, false},
				{{-1,-2,3,4,5,5,7,1}, true},
				{{-1,-2,3,7,5,6,7,1}, true},
				{{-2,-3,-4,-5,-6}, false},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = cycleCircularArray::loopExists(testcase);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}
	};
}