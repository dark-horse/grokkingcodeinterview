
#include "pch.h"
#include "CppUnitTest.h"
#include "..\slidingWindow\maxSumSubArray.h"
#include "..\slidingWindow\smallestSumWithGreaterSum.h"
#include "..\slidingWindow\longestSubstringWithKCharacters.h"
#include "..\slidingWindow\longestSubstringWithSameLetters.h"
#include "..\slidingWindow\permutationInString.h"
#include "..\slidingWindow\smallestWindowContainingSubstring.h"
#include "..\slidingWindow\wordsConcatenation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace slidingWindow
{
	TEST_CLASS(slidingWindowTests)
	{
	public:
		TEST_METHOD(checksmallestSumWithGreaterSum)
		{
			vector<tuple<vector<int>, int, int>> testcases =
			{
				{{23}, 2, 1 },
				{{1,2,3,4}, 1, 1 },
				{{1,2,3,4}, 10, 4 }, 
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = smallestSumWithGreatedSum::findMinSubArray(get<1>(testcases[i]), testcase);
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkLongestSubstringWithKCharacters)
		{
			vector<tuple<string, int, int>> testcases =
			{
				{"blah", 2, 2},
				{"bllah", 2, 3},
				{"bllaah", 2, 4},
				{"bllaaah", 2, 5},
				{"bllahhh", 2, 4},
				{"bllah", 1, 2},
				{"bllaah", 1, 2},
				{"bllahhh", 1, 3},
				{"hhhblla", 1, 3},
				{"araaci", 2, 4},
				{"araaci", 1, 2},
				{"cbbebi", 3, 5},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = longestSubstringWithKCharacters::findLength(testcase, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		
		TEST_METHOD(checkPermutationInString)
		{
			vector<tuple<string, string, bool>> testcases =
			{
				{"blah", "2", false},
				{"blah", "bla", true},
				{"blah", "abl", true},
				{"blah", "hla", true},
				{"oidbcaf", "abc", true},
				{"odicf", "dc", false},
				{"bcdxabcdy", "bcdyabcdx", true},
				{"aaacb", "aaacb", true},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = permutationInString::findPermutation(testcase, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkLongestSubstringWithSameLetters)
		{
			vector<tuple<string, int, int>> testcases =
			{
				{"blah", 2, 3},
				{"bllah", 2, 4},
				{"bllaah", 2, 4},
				{"bllaaah", 2, 5},
				{"bllahhh", 2, 5},
				{"bllah", 1, 3},
				{"bllaah", 1, 3},
				{"bllahhh", 1, 4},
				{"hhhblla", 1, 4},
				{"araaci", 2, 5},
				{"araaci", 1, 4},
				{"cbbebi", 3, 6},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = longestSubstringWithSameLetters::findLength(testcase, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkSmallestWindowContainingChars)
		{
			vector<tuple<string, string, string>> testcases =
			{
				{"blah", "ha", "ah"},
				{"blah", "aha", ""},
				{"blaaaaha", "ah", "ah"},
				{"aabdec", "abc", "abdec"},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = smallestWindowContainingSubstring::findSubstring(testcase, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkWordsConcatenation)
		{
			vector<tuple<string, vector<string>, vector<int>>> testcases =
			{
				{"blah", {"ha"}, {} },
				{"catfoxcat", {"cat", "fox"}, {0, 3}},
				{"catcatfoxfox", {"cat", "fox"}, {3}},
				{"catcatcatcat", {"cat", "cat"}, {0, 3, 6}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = wordsConcatenation::findWordConcatenationSlowPoke(testcase, get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}
	};
}