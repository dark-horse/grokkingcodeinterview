#include "pch.h"
#include "CppUnitTest.h"
#include "..\matrixTraversal\numberOfIslands.h"
#include "..\matrixTraversal\biggestIsland.h"
#include "..\matrixTraversal\floodFill.h"
#include "..\matrixTraversal\numberOfClosedIslands.h"
#include "..\matrixTraversal\containsCycle.h"
#include "..\matrixTraversal\distinctIslands.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsMatrixTraversal
{
    TEST_CLASS(testsMatrixTraversal)
    {
        TEST_METHOD(testNumberOfIslands)
        {
            vector<tuple<vector<vector<int>>, int>> testcases
            {
                {{{0, 1, 1, 1, 0}, {0, 0, 0, 1, 1}, {0, 1, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}}, 1},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 3},
                {{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}, 0},
                {{{0}, {0}, {0}, {0}, {0} }, 0 },
                {{{1}, {1}, {0}, {0}, {0} }, 1 },
                {{{1}, {1}, {0}, {1}, {1} }, 2 },
                {{{1}, {1}, {1}, {1}, {1} }, 1 },
                {{{0}, {1}, {0}, {1}, {0} }, 2 },
                {{{1}, {1}, {1}, {1}, {1} }, 1 },
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 3},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = get<0>(testcases[i]);
                auto res = numberOfIslands::countIslands(testcase);
                Assert::IsTrue(res == get<1>(testcases[i]));
            }
        }

        TEST_METHOD(testBiggestIsland)
        {
            vector<tuple<vector<vector<int>>, int>> testcases
            {
                {{{0, 1, 1, 1, 0}, {0, 0, 0, 1, 1}, {0, 1, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}}, 10},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 4},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 1, 0, 0}}, 5},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 4},
                {{{1, 1, 1, 1, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 0}, {1, 1, 1, 1, 0}}, 14},
                {{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}, 0},
                {{{0}, {0}, {0}, {0}, {0} }, 0 },
                {{{1}, {1}, {0}, {0}, {0} }, 2 },
                {{{1}, {1}, {0}, {1}, {1} }, 2 },
                {{{1}, {1}, {1}, {1}, {1} }, 5 },
                {{{0}, {1}, {0}, {1}, {0} }, 1 },
                {{{1}, {1}, {1}, {1}, {1} }, 5 },
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = get<0>(testcases[i]);
                auto res = biggestIsland::maxAreaOfIsland(testcase);
                Assert::IsTrue(res == get<1>(testcases[i]));
            }
        }

        TEST_METHOD(testFloodFill)
        {
            vector<tuple<vector<vector<int>>, int, int, vector<vector<int>>>> testcases
            {
                {{{0, 1, 1, 1, 0}, {0, 0, 0, 1, 1}, {0, 1, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}}, 0, 0, {{2, 1, 1, 1, 0}, {2, 2, 2, 1, 1}, {2, 1, 1, 1, 2}, {2, 1, 1, 2, 2}, {2, 2, 2, 2, 2}}},
                {{{0, 1, 1, 1, 0}, {0, 0, 0, 1, 1}, {0, 1, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}}, 0, 1, {{0, 2, 2, 2, 0}, {0, 0, 0, 2, 2}, {0, 2, 2, 2, 0}, {0, 2, 2, 0, 0}, {0, 0, 0, 0, 0}}},

                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 0, 0, {{2, 2, 2, 0, 0}, {0, 2, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 0, 4, {{1, 1, 1, 2, 2}, {0, 1, 2, 2, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 2, 1, {{1, 1, 1, 0, 0}, {2, 1, 0, 0, 1}, {2, 2, 1, 1, 0}, {2, 2, 1, 0, 0}, {2, 2, 1, 0, 0}}},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 4, 2, {{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 2, 2, 0}, {0, 0, 2, 0, 0}, {0, 0, 2, 0, 0}}},

                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 1, 0, 0}}, 0, 0, {{2, 2, 2, 0, 0}, {0, 2, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 1, 0, 0}}},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 4, 4, {{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 2}, {1, 0, 1, 2, 2}, {0, 0, 1, 2, 2}}},

                {{{1, 1, 1, 1, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 0}, {1, 1, 1, 1, 0}}, 3, 3, {{2, 2, 2, 2, 0}, {2, 0, 0, 2, 0}, {2, 0, 0, 2, 0}, {2, 0, 0, 2, 0}, {2, 2, 2, 2, 0}}},
                {{{1, 1, 1, 1, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 0}, {1, 1, 1, 1, 0}}, 2, 2, {{1, 1, 1, 1, 0}, {1, 2, 2, 1, 0}, {1, 2, 2, 1, 0}, {1, 2, 2, 1, 0}, {1, 1, 1, 1, 0}}},
                {{{1, 1, 1, 1, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 0}, {1, 1, 1, 1, 0}}, 4, 4, {{1, 1, 1, 1, 2}, {1, 0, 0, 1, 2}, {1, 0, 0, 1, 2}, {1, 0, 0, 1, 2}, {1, 1, 1, 1, 2}}},

                {{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}, 0, 0, {{2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}}},
                {{{0}, {0}, {0}, {0}, {0} }, 2, 0, {{2}, {2}, {2}, {2}, {2} } },
                {{{1}, {1}, {0}, {0}, {0} }, 0, 0, {{2}, {2}, {0}, {0}, {0} } },
                {{{1}, {1}, {0}, {1}, {1} }, 4, 0, {{1}, {1}, {0}, {2}, {2} }},
                {{{1}, {1}, {1}, {1}, {1} }, 0, 0, {{2}, {2}, {2}, {2}, {2} }},
                {{{0}, {1}, {0}, {1}, {0} }, 2, 0, {{0}, {1}, {2}, {1}, {0} } },
                {{{1}, {1}, {1}, {1}, {1} }, 1, 0, {{2}, {2}, {2}, {2}, {2} } },
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = get<0>(testcases[i]);
                auto res = floodFillClass::floodFill(testcase, get<1>(testcases[i]), get<2>(testcases[i]), 2);
                auto expected = get<3>(testcases[i]);
                Assert::IsTrue(res == expected);
            }
        }

        TEST_METHOD(testNumberOfClosedIslands)
        {
            vector<tuple<vector<vector<int>>, int>> testcases
            {
                {{{1,1,0,0,0}, {0,1,0,0,0}, {0,0,1,1,0}, {0,1,1,0,0}, {0, 0, 0, 0, 0}}, 1},
                {{{0, 1, 1, 1, 0}, {0, 0, 0, 1, 1}, {0, 1, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}}, 0},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 0},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}}, 1},
                {{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}, 0},
                {{{0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 0}}, 2},
                {{{0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}}, 2},
                {{{0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}}, 3},
                {{{0}, {0}, {0}, {0}, {0} }, 0 },
                {{{1}, {1}, {0}, {0}, {0} }, 0 },
                {{{1}, {1}, {0}, {1}, {1} }, 0 },
                {{{1}, {1}, {1}, {1}, {1} }, 0 },
                {{{0}, {1}, {0}, {1}, {0} }, 0 },
                {{{1}, {1}, {1}, {1}, {1} }, 0 },
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = get<0>(testcases[i]);
                auto res = numberOfClosedIslands::countClosedIslands(testcase);
                Assert::IsTrue(res == get<1>(testcases[i]));
            }
        }

        TEST_METHOD(testContainsCycle)
        {
            vector<tuple<vector<vector<char>>, bool>> testcases
            {
                {{{'a', 'a', 'a', 'a'}, {'b', 'a', 'c', 'a'}, {'b', 'a', 'c', 'a'}, {'b', 'a', 'c', 'a'}}, false},
                {{{'a', 'a', 'a', 'a'}, {'b', 'a', 'c', 'a'}, {'b', 'a', 'c', 'a'}, {'b', 'a', 'a', 'a'}}, true},
                {{{'a', 'a', 'a', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'b', 'a', 'a'}, {'a', 'a', 'a', 'c'}}, true},
                {{{'a', 'b', 'e', 'b'}, {'b', 'b', 'c', 'b'}, {'b', 'c', 'c', 'd'}, {'d', 'c', 'd', 'd'}}, false},
                {{{'x', 'o', 'o', 'x'}, {'x', 'x', 'o', 'x'}, {'y', 'y', 'o', 'x'}, {'x', 'x', 'x', 'x'}}, false},
                {{{'x', 'o', 'o', 'x'}, {'x', 'o', 'o', 'x'}, {'x', 'x', 'o', 'x'}, {'x', 'x', 'x', 'x'}}, true},
                {{{'x', 'o', 'o', 'x'}, {'x', 'x', 'o', 'x'}, {'x', 'o', 'o', 'x'}, {'x', 'x', 'x', 'x'}}, false},
                {{{'x', 'o', 'o', 'x'}, {'x', 'x', 'o', 'x'}, {'x', 'o', 'o', 'o'}, {'x', 'x', 'x', 'x'}}, false},
                {{{'x', 'o', 'o', 'x'}, {'x', 'x', 'o', 'x'}, {'x', 'x', 'o', 'o'}, {'x', 'x', 'o', 'o'}}, true},
                {{{'x', 'o', 'o', 'x'}, {'x', 'x', 'o', 'x'}, {'y', 'y', 'o', 'o'}, {'x', 'x', 'o', 'o'}}, true},
                {{{'x', 'o', 'o', 'o'}, {'x', 'x', 'o', 'x'}, {'x', 'x', 'o', 'x'}, {'x', 'x', 'o', 'x'}}, true},
                {{{'x', 'o', 'o', 'o'}, {'x', 'x', 'o', 'x'}, {'y', 'y', 'o', 'x'}, {'x', 'x', 'o', 'x'}}, false},
                {{{'x', 'o', 'o', 'x'}, {'x', 'x', 'x', 'x'}, {'x', 'x', 'x', 'x'}, {'x', 'x', 'x', 'x'}}, true},
                {{{'a', 'b', 'e', 'b'}, {'b', 'b', 'c', 'b'}, {'b', 'c', 'c', 'd'}, {'d', 'c', 'c', 'd'}}, true},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = get<0>(testcases[i]);
                auto res = containsCycle::hasCycle(testcase);
                Assert::IsTrue(res == get<1>(testcases[i]));
            }
        }

        TEST_METHOD(testDistinctIsland)
        {
            vector<tuple<vector<vector<int>>, int>> testcases
            {
                {{{1,1,0,0,0}, {0,1,0,0,0}, {0,0,1,1,0}, {0,1,1,0,0}, {0, 0, 0, 0, 0}}, 2},
                {{{1,1,0,0,0}, {0,1,0,0,0}, {0,0,1,1,0}, {0,0,0,1,0}, {0, 0, 0, 0, 0}}, 1},
                {{{1,1,0,0,0}, {0,1,0,0,0}, {0,0,1,1,0}, {1,1,0,1,0}, {0, 1, 0, 0, 0}}, 1},
                {{{1,1,0,1,1}, {0,1,0,0,0}, {0,0,1,1,0}, {1,1,0,1,0}, {0, 0, 0, 0, 0}}, 2},
                {{{0, 1, 1, 1, 0}, {0, 0, 0, 1, 1}, {0, 1, 1, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}}, 1},
                {{{0, 1, 1, 1, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 0}, {1, 1, 1, 0, 0}, {0, 0, 1, 1, 0}}, 1},
                {{{0, 1, 1, 1, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}}, 2},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}}, 3},
                {{{1, 1, 1, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}}, 3},
                {{{1, 1, 1, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 0}}, 2},
                {{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}, 0},
                {{{0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 0}}, 2},
                {{{0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}}, 2},
                {{{0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}}, 1},
                {{{0}, {0}, {0}, {0}, {0} }, 0 },
                {{{1}, {1}, {0}, {1}, {0} }, 2 },
                {{{1}, {1}, {0}, {0}, {0} }, 1 },
                {{{1}, {1}, {0}, {1}, {1} }, 1 },
                {{{1}, {1}, {1}, {1}, {1} }, 1 },
                {{{0}, {1}, {0}, {1}, {0} }, 1 },
                {{{1}, {1}, {1}, {1}, {1} }, 1 },
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = get<0>(testcases[i]);
                auto res = distinctIslands::findDistinctIslandsDFS(testcase);
                Assert::IsTrue(res == get<1>(testcases[i]));
            }
        }
    };
}
