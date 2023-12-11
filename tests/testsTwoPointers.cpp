#include "pch.h"
#include <unordered_map>		// you need this for tuple. (God, how I hate C++)
#include "CppUnitTest.h"
#include "..\twoPointers\pairWithTarget.h"
#include "..\twoPointers\nonDuplicateItems.h"
#include "..\twoPointers\squaringSortedArray.h"
#include "..\twoPointers\tripletSumToZero.h"
#include "..\twoPointers\tripletSumCloseToTarget.h"
#include "..\twoPointers\tripletSmallerSum.h"
#include "..\twoPointers\subarraysProductLessThanTarget.h"
#include "..\twoPointers\dutchNationalFlag.h"
#include "..\twoPointers\quadrupletSumToTarget.h"
#include "..\twoPointers\compareStringsBackspace.h"
#include "..\twoPointers\minimumWindowSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testsTwoPointers
{
	TEST_CLASS(tests)
	{
	public:
		TEST_METHOD(checkPairWithTarget)
		{
			vector<tuple<vector<int>, int, vector<int>>> testcases =
			{
				{ {1,2,3,4,6}, 6, {1, 3}},
				{ {2, 5, 9, 11}, 11, {0, 2}},
				{ {2, 5, 9, 11}, 7, {0, 1}},
				{ {2, 5, 9, 11}, 14, {1, 2}},
				{ {2, 5, 9, 11}, 16, {1, 3}},
				{ {1,2,}, 3, {0, 1}},
				{ {1,2,3}, 4, {0, 2}},
				{ {0,1,2,3,4,6}, 10, {4, 5}},
				{ {0, 1, 2, 3, 4}, 0, {-1, -1}},
				{ {0, 1, 2, 3, 4}, -1, {-1, -1}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> res = pairWithTarget::search(get<0>(testcases[i]), get<1>(testcases[1]));
				Assert::IsTrue(res.size() == 2);
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkNonDuplicateItems)
		{
			vector<tuple<vector<int>, int>> testcases =
			{
				{ {1}, 1},
				{ {1,1}, 1},
				{ {1,1,1}, 1},
				{ {1,1,1,1,1}, 1},
				{ {0,1}, 2},
				{ {1,2,3,4,6}, 5},
				{ {1,1,1,4,6}, 3},
				{ {1,1,1,4,4}, 2},
				{ {1,2,2,2,6}, 3},
				{ {1,2,3,3,3}, 3},
				{ {1,1,1,1,1,2,2,2,2,3,3,4,5,5,5,6,7,8,9,9,9,9,10}, 10},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> test = get<0>(testcases[i]);
				int res = nonDuplicateItems::remove(test);
				Assert::IsTrue(res == get<1>(testcases[i]));
				for (int i = 1; i < res; i++)
				{
					Assert::IsTrue(test[i-1] < test[i]);
				}
			}
		}

		TEST_METHOD(checkSquaringSortedArray)
		{
			vector<tuple<vector<int>, vector<int>>> testcases =
			{
				{ {-3,-2,-1}, {1,4,9}},
				{ {1}, {1}},
				{ {1,1}, {1,1}},
				{ {1,1,1}, {1,1,1}},
				{ {1,1,1,1,1}, {1,1,1,1,1}},
				{ {0,2}, {0,4}},
				{ {-1,2,3,4,6}, {1,4,9,16,36}},
				{ {-2, -1, 2, 3}, {1, 4, 4, 9}},
				{ {-2, -1, 1}, {1, 1, 4}},
				{ {-2, 1, 1}, {1, 1, 4}},
				{ {-2, 1, 11}, {1, 4, 121}},
				{ {-20, 1, 11}, {1, 121, 400}},
				{ {-2, -1, -1, 3}, {1, 1, 4, 9}},
				{ {-2,  1, 2, 3}, {1, 4, 4, 9}},
				{ {-2, -1, 0, 2, 3}, {0, 1, 4, 4, 9}},
				{ {-3, -1, 0, 1, 2}, {0, 1, 1, 4, 9}},
				{ {-3, -2, -1, 1, 2}, {1, 1, 4, 4, 9}},
				{ {-5, -3, -3, 1, 2}, {1, 4, 9, 9, 25}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> test = get<0>(testcases[i]);
				vector<int> res = squaringSortedArray::makeSquares(test);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}


		TEST_METHOD(checkTripletSumToZero)
		{
			vector<tuple<vector<int>, vector<int>>> testcases =
			{
				{ {-3, 0, 1, 2, -1, 1, -2}, {}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> test = get<0>(testcases[i]);
				vector<vector<int>> res = tripletSumToZero::searchTriplets(test);
			}
		}

		TEST_METHOD(checkTripletCloseToTarget)
		{
			vector<tuple<vector<int>, int, int>> testcases =
			{
				{ {-1, 0, 2, 3}, 3, 2},
				{ {-1, 0, 0, 3}, 3, 3},
				{ {-1, 0, 2, 3}, 2, 2},
				{ {1, 0, 1, 1}, 100, 3},
				{ {0, 0, 1, 1, 2, 6}, 5, 4},
				{ {0, 0, 1, 1, 2, 6}, 6, 6},
				{ {0, 0, 1, 1, 2, 6}, 8, 8},
				{ {0, 0, 1, 1, 2, 6}, 9, 9},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> test = get<0>(testcases[i]);
				int res = tripletSumCloseToTarget::searchTriplet(test, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkTripletSmallerSum)
		{
			vector<tuple<vector<int>, int, int>> testcases =
			{
				{ {-1, 0, 2, 3}, 3, 2},
				{ {-1, 4, 2, 1, 3}, 5, 4},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> test = get<0>(testcases[i]);
				int res = tripletSmallerSum::searchTriplets(test, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkSubarraysProductLessThanTarget)
		{
			vector<tuple<vector<int>, int, vector<vector<int>>>> testcases =
			{
				{ {2, 5, 3, 10}, 30, {{2}, {2,5}, {5}, {5,3}, {3}, {10}}},
				{ {8, 2, 6, 5}, 50, {{8}, {8,2}, {2}, {2,6}, {6}, {6,5}, {5}}},
				{ {8, 2, 3, 5}, 50, {{8}, {8,2}, {8,2,3}, {2}, {2,3}, {2,3,5},{3}, {3,5},{5}}},
				{ {8, 2, 3, 5}, 1, {}},
				{ {8}, 1, {}},
				{ {}, 1, {}},
				{ {1}, 1, {}},
				{ {1}, 2, {{1}}},
				{ {1,1}, 2, {{1},{1,1}, {1}}},
				{ {1,1,1}, 2, {{1}, {1,1}, {1,1,1}, {1}, {1,1}, {1}}},
				{ {8, 2, 3, 5}, 8, {{2}, {2,3}, {3}, {5}}},
				{ {8, 2, 3, 9}, 8, {{2}, {2,3}, {3}}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> test = get<0>(testcases[i]);
				auto res = subarraysProductLessThanTarget::findSubarrays(test, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkSubarraysProductLessThanTargetSlidingWindow)
		{
			vector<tuple<vector<int>, int, vector<vector<int>>>> testcases =
			{
				{ {2, 5, 3, 10}, 30, {{2}, {5}, {2,5}, {3}, {5,3}, {10}}},
				{ {8, 2, 6, 5}, 50, {{8}, {2}, {8,2}, {6}, {2,6}, {5}, {6,5}}},
				{ {8, 2, 3, 5}, 50, {{8}, {2}, {8, 2}, {3}, {2,3}, {8,2,3}, {5}, {3,5}, {2,3,5}, }},
				{ {8, 2, 3, 5}, 1, {}},
				{ {8, 2, 3, 5}, 2, {}},
				{ {8, 2, 3, 5, 1}, 2, {{1}}},
				{ {8}, 1, {}},
				{ {}, 1, {}},
				{ {1, 7, 2}, 6, {{1}, {2}}},
				{ {1, 7, 2, 7}, 6, {{1}, {2}}},
				{ {1, 7, 2, 7, 5}, 6, {{1}, {2}, {5}}},
				{ {1, 7, 2, 7, 5, 7}, 6, {{1}, {2}, {5}}},
				{ {}, 1, {}},
				{ {1}, 2, {{1}}},
				{ {1,1}, 2, {{1}, {1},{1,1}}},
				{ {1,1,1}, 2, {{1}, {1}, {1,1}, {1}, {1,1}, {1,1,1}}},
				{ {8, 2, 3, 5}, 8, {{2}, {3}, {2,3}, {5}}},
				{ {8, 2, 3, 9}, 8, {{2}, {3}, {2,3}}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> test = get<0>(testcases[i]);
				auto res = subarraysProductLessThanTarget::findSubarraysSlidingWindow(test, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkDutchNationalFlag)
		{
			vector<tuple<vector<int>, vector<int>>> testcases =
			{
				{{2, 2, 0, 1, 2, 0}, {0,0,1,2,2,2}},
				{ {1, 1, 2, 1}, {1, 1, 1, 2}},
				{ {1, 1, 2, 1,0}, {0, 1, 1, 1, 2}},
				{ {1, 1, 2, 2, 1,0}, {0, 1, 1, 1, 2 ,2}},
				{ {1, 1, 2, 2}, {1, 1, 2, 2}},
				{ {0, 0, 0, 0}, {0, 0, 0, 0}},
				{ {1, 1, 1, 1}, {1, 1, 1, 1}},
				{ {2, 2, 2, 2}, {2, 2, 2, 2}},
				{ {0, 0}, {0, 0}},
				{ {2, 1}, {1, 2}},
				{ {2, 0}, {0, 2}},
				{ {0, 1}, {0, 1}},
				{ {1, 0}, {0, 1}},
				{ {2, 1,0}, {0, 1, 2}},
				{ {1, 2,0}, {0, 1, 2}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> test = get<0>(testcases[i]);
				auto res = dutchNationalFlag::sort(test);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkQuadrupleSumToTarget)
		{
			vector<tuple<vector<int>, int, vector<vector<int>>>> testcases =
			{
				{ {2, 5, 1, 3, 0}, 6, {{2,1, 3, 0}}},
				{ {2, 0, 1, 0}, 3, {{2,0, 1, 0}}},
				{ {2, 0, 1, 0, 1}, 4, {{2,0, 1, 0}}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				vector<int> test = get<0>(testcases[i]);
				auto res = quadrupleSumToTarget::searchQuadruplets(test, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkCompareStringsBackspace)
		{
			vector<tuple<string, string, bool>> testcases =
			{
				{"hello", "hello", true},
				{"hella#o", "hello", true},
				{"xy#z", "xzz#", true},
				{"xy#z", "xyz#", false},
				{"xp#", "xyz##", true},
				{"xywrrmp", "xywrrmu#p", true},
				{"abc###", "", true},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				string test = get<0>(testcases[i]);
				auto res = compareStringsBackspace::compare(test, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkMinimumWindowSort)
		{
			vector<tuple<vector<int>, int>> testcases =
			{
				{{2,1}, 2},
				{{1,2}, 0},
				{{1, 3, 2, 0, -1, 7, 10}, 5},
				{{3, 2, 1}, 3},
				{{1, 2, 5, 3, 7, 10, 9, 12}, 5},
				{{1,2,3,9,2,3,7}, 5},
				{{1,2,3,4,3}, 2},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto test = get<0>(testcases[i]);
				auto res = minimumWindowSort::sort(test);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}
	};
}
