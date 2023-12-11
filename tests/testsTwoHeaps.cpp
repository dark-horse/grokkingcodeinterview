#include "pch.h"
#include "CppUnitTest.h"
#include "..\twoHeaps\medianNumberStream.h"
#include "..\twoHeaps\slidingWindowMedian.h"
#include "..\twoHeaps\maximizeCapital.h"
#include "..\twoHeaps\nextInterval.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsTwoHeaps
{
    TEST_CLASS(testsTwoHeaps)
    {
        TEST_METHOD(checkMedianNumberStream)
        {
            medianNumberStream test;
            test.insertNum(3);
            test.insertNum(1);
            Assert::IsTrue(test.findMedian() == 2);
            test.insertNum(5);
            Assert::IsTrue(test.findMedian() == 3);
            test.insertNum(4);
            Assert::IsTrue(test.findMedian() == 3.5);
            test.insertNum(10);
            Assert::IsTrue(test.findMedian() == 4);
            test.insertNum(2);
            Assert::IsTrue(test.findMedian() == 3.5);
            test.insertNum(10);
            Assert::IsTrue(test.findMedian() == 4);
        }

        TEST_METHOD(checkSlidingWindowMedian)
        {
            vector<tuple<vector<int>, int, vector<double>>> testcases =
            {
                {{1, 2, -1, 3, 5}, 2,{1.5, 0.5, 1.0, 4.0}},
                {{1, 2, -1, 3, 5}, 3,{1.0, 2.0, 3.0}},
                {{1, 2, -1, 3, 5}, 4,{1.5, 2.5}},
                {{1, 2, -1, 3, 5}, 5,{2.0}},
                {{-1, -2, -3, -4, -5},3,{-2, -3, -4} },
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = get<0>(testcases[i]);
                auto output = slidingWindowMedian::findSlidingWindowMedian(testcase, get<1>(testcases[i]));
                Assert::IsTrue(output == get<2>(testcases[i]));
            }
        }

        TEST_METHOD(checkMaximizeCapital)
        {
            vector<tuple<vector<int>, vector<int>, int, int, int >> testcases =
            {
                {{3,2,1},{100,2,30},2,1,131},
                {{0,1,2},{1,2,3},2,1,6},
                {{0,1,2,3},{1,2,3,5},3,0,8},
                {{100,100,100,100},{1,1,1,1},2,1000,1002},
                {{100,100,100,100},{1,1,1,1},3,1000,1003},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = get<0>(testcases[i]);
                auto output = maximizeCapital::findMaximumCapital(testcase, get<1>(testcases[i]), get<2>(testcases[i]), get<3>(testcases[i]));
                Assert::IsTrue(output == get<4>(testcases[i]));
            }
        }

        TEST_METHOD(checkNextInterval)
        {
            vector<tuple<vector<vector<int>>, vector<int>>> testcases =
            {
                {{{3,4},{2,3},{5,6}},{2,0,-1}},
                {{{3,4},{2,4},{5,6}},{2,2,-1}},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = get<0>(testcases[i]);
                auto input = nextInterval::constructIntervals(testcase);
                auto output = nextInterval::findNextInterval(input);
                Assert::IsTrue(output == get<1>(testcases[i]));
            }
        }
    };
}