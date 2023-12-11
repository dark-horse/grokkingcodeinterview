#include "pch.h"
#include "CppUnitTest.h"
#include "..\solutions\containsDuplicates.h"
#include "..\solutions\pangram.h"
#include "..\solutions\mysqrt.h"
#include "..\solutions\reverseVowels.h"
#include "..\solutions\validPalindrome.h"
#include "..\solutions\validAnagram.h"
#include "..\solutions\goodPairs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testsWarmup
{
	TEST_CLASS(tests)
	{
	public:
		
		TEST_METHOD(duplicates)
		{
			auto s = containsDuplicates();
			vector<int> arr = vector<int>();
			auto rest = s.containsDuplicate(arr);
			Assert::IsFalse(rest);

			arr = { 1, 2, 3 };
			rest = s.containsDuplicate(arr);
			Assert::IsFalse(rest);

			arr = { 1, 2, 3 , 1};
			rest = s.containsDuplicate(arr);
			Assert::IsTrue(rest);
		}

		TEST_METHOD(checkPangram)
		{
			auto s = pangram();
			Assert::IsTrue(s.checkIfPangram("TheQuickBrownFoxJumpsOverTheLazyDog"));
			Assert::IsFalse(s.checkIfPangram("This is not a pangram"));
		}

		TEST_METHOD(checkSqrt)
		{
			auto s = mysqrt();

			for (int i = 0; i < 1024*1024*1024; i++)
			{
				int r = s.mySqrt(i);
				long long r_sq = r * r;
				Assert::IsTrue(r_sq <= i && r_sq + 2 * r + 1 > i);
			}
		}

		TEST_METHOD(checkFastSqrt)
		{
			auto s = mysqrt();

			for (int i = 0; i < 1024*1024*1024 ; i++)
			{
				int r = s.fastSqrt(i);
				long long r_sq = r * r;
				Assert::IsTrue(r_sq <= i && r_sq + 2 * r + 1 > i);
			}
		}

		TEST_METHOD(checkReverseVowels)
		{
			auto r = reverseVowels();
			auto s = std::string("hello");
			r.reverse(s);
			Assert::IsTrue(strcmp(s.c_str(), "holle") == 0);

			vector<pair<string, string>> testcases =
			{
				make_pair("hello", "holle"),
				make_pair("Aa", "aA"),
				make_pair("a", "a"),
				make_pair("AsA", "AsA"),
				make_pair("", ""),
				make_pair("bas", "bas"),
				make_pair("baA", "bAa"),
				make_pair("hllo", "hllo"),
				make_pair("hell", "hell"),
				make_pair("aaaA", "Aaaa"),
				make_pair("dfsg", "dfsg"),
				make_pair("dfs", "dfs"),
				make_pair("df", "df"),
				make_pair("d", "d"),
			};


			for (int i = 0; i < testcases.size(); i++)
			{
				s = std::string(testcases[i].first);
				r.reverse(s);
				Assert::IsTrue(strcmp(s.c_str(), testcases[i].second.c_str()) == 0);
			}
		}

		TEST_METHOD(checkValidPalindrome)
		{
			auto p = validPalindrome();

			vector<pair<string, bool>> testcases =
			{
				make_pair("hello", false),
				make_pair("A man, a plan, a canal, Panama!", true),
				make_pair("Was it a car or a cat I saw?", true),
			};


			for (int i = 0; i < testcases.size(); i++)
			{
				bool res = p.valid(testcases[i].first.c_str());
				Assert::IsTrue(res == testcases[i].second);
			}
		}

		TEST_METHOD(checkValidAnagram)
		{
			auto p = validAnagram();

			vector<tuple<string, string, bool>> testcases =
			{
				{"hello", "hello", true},
				{"rat", "tra", true},
				{"rat", "car", false},
				{"car", "rac", true},
				{"listen", "silent", true},
				{"", "", true},
				{"a", "a", true},
				{"as", "sa", true},
				{"a", "B", false},
				{"crack", "rackc", true},
				{"crack", "acckr", true},
				{"crack", "rack", false},
				{"hello", "ehllo", true},
				{"hello", "ehlo", false},
				{"ccccc", "ccccc", true},
				{"c", "ccccc", false},
				{"cc", "ccccc", false},
				{"hello", "world", false},
			};


			for (int i = 0; i < testcases.size(); i++)
			{
				bool res = p.valid(get<0>(testcases[i]), get<1>(testcases[i]));
				Assert::IsTrue(res == get<2>(testcases[i]));
			}
		}

		TEST_METHOD(checkGoodPairs)
		{
			auto p = goodPairs();

			vector<tuple<vector<int>, int>> testcases =
			{
				{ {1,1}, 1},
				{ {1,2,3,1,2,1}, 4},
				{ {1,2,3,1,1,3}, 4},
				{ {1,1,1,1}, 6},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				int pairs = p.pairCount(get<0>(testcases[i]));
				Assert::IsTrue(pairs == get<1>(testcases[i]));
			}
		}
	};
}
