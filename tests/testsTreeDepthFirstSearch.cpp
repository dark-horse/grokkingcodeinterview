#include "pch.h"
#include "CppUnitTest.h"
#include "..\depthFirstTreeSearch\allPathsForSum.h"
#include "..\depthFirstTreeSearch\countPathsForSum.h"
#include "..\depthFirstTreeSearch\maxSumPath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsTreeDepthFirstSearch
{
    TEST_CLASS(treeDepthFirstSearchTests)
    {
        TEST_METHOD(checkAllPathsForSum)
        {
            vector<tuple<vector<int>, int, vector<vector<int>>>> testcases
            {
                {{1, 7, 4, INT32_MIN,INT32_MIN, 5, INT32_MIN, INT32_MIN, 9, 2, INT32_MIN, INT32_MIN, 7, INT32_MIN, INT32_MIN}, 12,{{1,7,4}, {1,9,2}}},
                {{12, 7,4, INT32_MIN, INT32_MIN, INT32_MIN,1,10, INT32_MIN, INT32_MIN,5, INT32_MIN, INT32_MIN},23,{{12,7,4}, {12,1,10}}}
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                int index = 0;
                auto input = allPathsForSum::vec2TreeNode(get<0>(testcases[i]),index);
                auto res = allPathsForSum::findPaths(input, get<1>(testcases[i]));
                Assert::IsTrue(res == get<2>(testcases[i]));
            }
        }

        TEST_METHOD(checkCountPathsForSum)
        {
            vector<tuple<vector<int>, int, int>> testcases
            {
                {{1, 7, 11, INT32_MIN, INT32_MIN, INT32_MIN, 9, INT32_MIN, INT32_MIN}, 12,0},
                {{1, 7, 6, INT32_MIN, INT32_MIN, 5, INT32_MIN, INT32_MIN, 9, 2 , INT32_MIN, INT32_MIN, 3, INT32_MIN, INT32_MIN}, 12,3},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                int index = 0;
                auto input = countPathsForSum::vec2TreeNode(get<0>(testcases[i]), index);
                auto res = countPathsForSum::countPaths(input, get<1>(testcases[i]));
                Assert::IsTrue(res == get<2>(testcases[i]));
            }
        }

        TEST_METHOD(checkMaxSumPath)
        {
            vector<tuple<vector<int>, int>> testcases
            {
                {{1, 7, 11, INT32_MIN, INT32_MIN, INT32_MIN, 9, INT32_MIN, INT32_MIN}, 28},
                {{1, 2, 4, INT32_MIN, INT32_MIN, INT32_MIN, 3,5 , INT32_MIN, INT32_MIN,6 , INT32_MIN, INT32_MIN}, 16},
                {{1, 2, 1, INT32_MIN, INT32_MIN, 3, INT32_MIN, INT32_MIN, 3,5,7, INT32_MIN, INT32_MIN,8, INT32_MIN, INT32_MIN, 6,9, INT32_MIN}, 31},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                int index = 0;
                auto input = maxSumPath::vec2TreeNode(get<0>(testcases[i]), index);
                auto res = maxSumPath::findMaximumPathSum(input);
                Assert::IsTrue(res == get<1>(testcases[i]));
            }
        }
    };
}