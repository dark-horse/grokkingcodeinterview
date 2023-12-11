#include "pch.h"
#include "CppUnitTest.h"
#include "..\modifiedBinarySearch\numberCeiling.h"
#include "..\modifiedBinarySearch\nextLetter.h"
#include "..\modifiedBinarySearch\numberRange.h"
#include "..\modifiedBinarySearch\minDiff.h"
#include "..\modifiedBinarySearch\searchBitonicArr.h"
#include "..\modifiedBinarySearch\searchRotatedArray.h"
#include "..\modifiedBinarySearch\rotationCount.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsModifiedBinarySearch
{
    TEST_CLASS(testsModifiedBinarySearch)
    {
        TEST_METHOD(checkNumberCeiling)
        {
            vector<tuple<vector<int>, int, int>> tests
            {
                {{4, 6, 10}, 4, 0},
                {{4, 6, 10}, 6, 1},
                {{4, 6, 10}, 10, 2},
                {{4, 6, 10}, -1, 0},
                {{4, 6, 10}, 17, -1},
                {{1, 3, 8, 10, 15}, 12, 4},
            };

            for (auto test : tests)
            {
                auto result = numberCeiling::searchCeilingOfANumber(get<0>(test), get<1>(test));
                Assert::IsTrue(result == get<2>(test));
            }
        }

        TEST_METHOD(checkNextLetter)
        {
            vector<tuple<vector<char>, char, char>> tests
            {
                {{'a', 'c', 'f', 'h'}, 'a', 'c'},
                {{'a', 'c', 'f', 'h'}, 'f', 'h'},
                {{'c', 'c', 'f', 'h'}, 'a', 'c'},
                {{'a', 'c', 'f', 'h'}, 'x', 'a'},
                {{'a', 'c', 'f', 'h'}, 'b', 'c'},
                {{'a', 'c', 'f', 'h'}, 'm', 'a'},
                {{'a', 'c', 'f', 'h'}, 'a', 'c'},
            };

            for (auto test : tests)
            {
                auto result = nextLetter::searchNextLetter(get<0>(test), get<1>(test));
                Assert::IsTrue(result == get<2>(test));
            }
        }

        TEST_METHOD(checkNumberRange)
        {
            vector<tuple<vector<int>, int, vector<int>>> tests
            {
                {{1, 1, 1, 1, 1, 1, 1, 1}, 1, {0,7}},
                {{4, 6, 6, 6, 9}, 4, {0,0}},
                {{4, 6, 6, 6, 9}, 6, {1,3}},
                {{4, 6, 6, 6, 9}, 9, {4,4}},
                {{1, 3, 8, 10, 15}, 10, {3,3}},
                {{1, 3, 8, 10, 15}, 1, {0,0}},
                {{1, 3, 8, 10, 15}, 15, {4,4}},
                {{1, 3, 8, 10, 15}, 12, {-1,-1}},
            };
            for (auto test : tests)
            {
                auto result = numberRange::findRange(get<0>(test), get<1>(test));
                Assert::IsTrue(result == get<2>(test));
            }
        }

        TEST_METHOD(checkMinDiff)
        {
            vector<tuple<vector<int>, int, int>> tests
            {
                {{4, 6, 10}, 5, 4},
                {{4, 6, 10}, 6, 6},
                {{4, 6, 10}, 10, 10},
                {{4, 6, 10}, -1, 4},
                {{4, 6, 10}, 17, 10},
                {{1, 3, 8, 10, 15}, 12, 10},
                {{1, 3, 8, 10, 15}, 13, 15},
                {{1, 3, 8, 10, 15}, 9, 8},
            };

            for (auto test : tests)
            {
                auto result = minDiff::searchMinDiffElement(get<0>(test), get<1>(test));
                Assert::IsTrue(result == get<2>(test));
            }
        }

        TEST_METHOD(checkSearchBitonicArr)
        {
            vector<tuple<vector<int>, int, int>> tests
            {
                {{4, 6, 10}, 4, 0},
                {{4, 6, 10}, 6, 1},
                {{4, 6, 10}, 10, 2},
                {{4, 6, 10}, -1, -1},
                {{4, 6, 10}, 17, -1},
                {{1, 3, 8, 10, 15}, 15, 4},
                {{15,10, 8, 3, 1}, 15, 0},
                {{15,10, 8, 3, 1}, 10, 1},
                {{15,10, 8, 3, 1}, 1, 4},
                {{15,10, 8, 3, 1}, 12, -1},
                {{15,10, 8, 3, 1}, 17, -1},
                {{1, 3, 8, 4, 3}, 4, 3},
                {{1, 3, 8, 4, 3}, 8, 2},
                {{1, 3, 8, 4, 3}, 1, 0},
                {{3, 8, 3, 1}, 8, 1},
                {{1, 3, 8, 12}, 12, 3},
                {{10, 9, 8}, 10, 0},
                {{1, 3, 8, 4, 3}, 3, 1},        // pick the earliest one when more than 1 item matches the key.
            };

            for (auto test : tests)
            {
                auto result = searchBitonicArr::search(get<0>(test), get<1>(test));
                Assert::IsTrue(result == get<2>(test));
            }
        }

        TEST_METHOD(checkSearchRotatedArray)
        {
            vector<tuple<vector<int>, int, int>> tests
            {
                {{4, 5, 6, 7, 0, 1, 2, 3}, 0, 4},
                {{10, 15, 1, 3, 8}, 8, 4},
                {{10, 15, 1, 3, 8}, 10, 0},
                {{10, 15, 1, 3, 8}, 15, 1},
                {{10, 15, 1, 3, 8}, 1, 2},
                {{10, 15, 1, 3, 8}, 3, 3},
                {{10, 15, 1, 3, 8}, 16, -1},
                {{10, 15, 1, 3, 8}, 2, -1},
                {{10, 15, 1, 3, 8}, 14, -1},
                {{10, 15, 1, 3, 8}, 16, -1},
                {{10, 15, 16, 23, 38}, 38, 4},
                {{10, 15, 16, 23, 38}, 10, 0},
                {{10, 15, 16, 23, 38}, 16, 2},
            };

            for (auto test : tests)
            {
                auto result = searchRotatedArray::search(get<0>(test), get<1>(test));
                Assert::IsTrue(result == get<2>(test));
            }
        }

        TEST_METHOD(checkSearchRotationCount)
        {
            vector<tuple<vector<int>, int>> tests
            {
                {{10, 20, 30, 10, 20}, 3},
            };

            for (auto test : tests)
            {
                auto result = rotationCount::countRotations(get<0>(test));
                Assert::IsTrue(result == get<1>(test));
            }
        }
    };
}