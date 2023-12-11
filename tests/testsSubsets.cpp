#include "pch.h"
#include "CppUnitTest.h"
#include <algorithm>
#include "..\subsets\subsets.h"
#include "..\subsets\subsetsWithDuplicates.h"
#include "..\subsets\permutations.h"
#include "..\subsets\stringPermutationsChangeCase.h"
#include "..\subsets\balancedParens.h"
#include "..\subsets\uniqueGeneralizedAbbr.h"
#include "..\subsets\evaluateExpression.h"
#include "..\subsets\structurallyUniqueBSTs.h"
#include "..\subsets\countOfStructurallyDifferentBSTs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsSubsets
{
    TEST_CLASS(testsSubsets)
    {
        TEST_METHOD(checkSubsets)
        {
            vector<tuple<vector<int>, vector<vector<int>>>> testcases
            {
                {{1,2}, {{},{1},{2},{1,2}}},
                {{1,2,3}, {{},{1},{2}, {3},{1,2},{1,3},{2,3},{1,2,3}}},
                {{1,2,3,4}, {{},{1},{2},{3},{4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4},{1,2,3},{1,2,4},{1,3,4},{2,3,4},{1,2,3,4}}},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = testcases[i];
                auto output = subsets::findSubsets(get<0>(testcase));
                auto expect = get<1>(testcase);
                Assert::IsTrue(output == expect);
            }
        }

        TEST_METHOD(checkSubsetsNoDuplicates)
        {
            vector<tuple<vector<int>, vector<vector<int>>>> testcases
            {
                {{}, {{}}},
                {{1}, {{},{1}}},
                {{1,2}, {{},{1},{2},{1,2}}},
                {{3,1,3}, {{},{1},{3},{1,3},{3,3},{1,3,3}}},
                {{3,1,3,3}, {{},{1},{3},{1,3},{3,3},{1,3,3},{3,3,3},{1,3,3,3}}},
                {{1,2,3}, {{},{1},{2}, {3},{1,2},{1,3},{2,3},{1,2,3}}},
                {{1,2,3,4}, {{},{1},{2},{3},{4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4},{1,2,3},{1,2,4},{1,3,4},{2,3,4},{1,2,3,4}}},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = testcases[i];
                auto output = subsetsWithDuplicate::findSubsets(get<0>(testcase));
                auto expect = get<1>(testcase);
                Assert::IsTrue(output == expect);
            }
        }

        TEST_METHOD(checkPermutations)
        {
            vector<tuple<vector<int>, vector<vector<int>>>> testcases
            {
                {{}, {}},
                {{1}, {{1}}},
                {{1,2}, {{1,2},{2,1}}},
                {{1,2,3}, {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,2,1},{3,1,2}}},
                {{1,2,3,4}, {{1,2,3,4}, {1,2,4,3}, {1,3,2,4}, {1,3,4,2}, {1,4,3,2}, {1,4,2,3},
                             {2,1,3,4}, {2,1,4,3}, {2,3,1,4}, {2,3,4,1}, {2,4,3,1}, {2,4,1,3},
                             {3,2,1,4}, {3,2,4,1}, {3,1,2,4}, {3,1,4,2}, {3,4,1,2}, {3,4,2,1},
                             {4,2,3,1}, {4,2,1,3}, {4,3,2,1}, {4,3,1,2}, {4,1,3,2}, {4,1,2,3},}},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = testcases[i];
                auto output = permutations::findPermutations(get<0>(testcase));
                auto expect = get<1>(testcase);
                Assert::IsTrue(output == expect);
            }
        }

        TEST_METHOD(checkStringPermutations)
        {
            vector<tuple<string, vector<string>>> testcases
            {
                {"ab4F", {"ab4F","ab4f","aB4F","aB4f","Ab4F","Ab4f","AB4F","AB4f"}},
                {"ab4", {"ab4", "aB4","Ab4","AB4"}},
            };

            for (int i = 0; i < testcases.size(); i++)
            {
                auto testcase = testcases[i];
                auto output = stringPermutationsChangeCase::findLetterCaseStringPermutations(get<0>(testcase));
                auto expect = get<1>(testcase);
                std::sort(output.begin(), output.end());
                std::sort(expect.begin(), expect.end());
                Assert::IsTrue(output == expect);
            }
        }

        TEST_METHOD(checkBalancedParens)
        {
            vector<tuple<int, vector<string>>> tests
            {
                {0, {}},
                {1, {"()"}},
                {2, {"(())", "()()"}},
                {3, {"((()))", "(()())", "(())()", "()(())", "()()()"}},
                {4, {"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"}},
            };

            for (auto test: tests)
            {
                auto output = balancedParens::generateValidParentheses(get<0>(test));
                auto expect = get<1>(test);
                std::sort(output.begin(), output.end());
                std::sort(expect.begin(), expect.end());
                Assert::IsTrue(output == expect);
            }
        }

        TEST_METHOD(checkUniqueGeneralizedAbbr)
        {
            vector<tuple<string, vector<string>>> tests
            {
                {"ab",{"ab", "1b", "a1", "2"}},
                {"BAT", {"BAT", "BA1", "B1T", "B2", "1AT", "1A1", "2T", "3"}},
                {"code", {"code", "cod1", "co1e", "co2", "c1de", "c1d1", "c2e", "c3", "1ode", "1od1", "1o1e", "1o2", "2de", "2d1", "3e", "4"}},
            };

            for (auto test : tests)
            {
                auto output = uniqueGeneralizedAbbr::generateGeneralizedAbbreviation(get<0>(test));
                auto expect = get<1>(test);
                std::sort(output.begin(), output.end());
                std::sort(expect.begin(), expect.end());
                Assert::IsTrue(output == expect);
            }
        }

        TEST_METHOD(checkEvaluateExpression)
        {
            vector<tuple<string, vector<int>>> tests
            {
                {"1*3",{3}},
                {"15*3",{45}},
                {"15*15",{225}},
                {"1-3",{-2}},
                {"1+3",{4}},
                {"1+3*2",{8,7}},
                {"1+2*3",{7,9}},
                {"1*5+10",{15,15}},
                {"2*3-4-5",{8, -12, 7, -7, -3}},
                {"2*5+10-5+4",{12,28,12,28,28,11,19,21,11,24,24,19,29,19}},
                {"2*5+10-5+4-6",{24,24,16,0,16,24,24,16,16,0,16,0,16,16,17,17,13,5,13,27,27,17,17,18,18,13,23,13,6,22,6,22,22,5,13,15,5,18,18,13,23,13}},
            };

            for (auto test : tests)
            {
                auto output = evaluateExpression::diffWaysToEvaluateExpression(get<0>(test));
                auto expect = get<1>(test);
                std::sort(output.begin(), output.end());
                std::sort(expect.begin(), expect.end());
                Assert::IsTrue(output == expect);
            }
        }

        TEST_METHOD(checkStructurallyUniqueBSTs)
        {
            vector<tuple<int, int>> tests
            {
                {1,1},
                {2,2},
                {3,5},
                {4,14},
                {5, 42}
            };

            for (auto test : tests)
            {
                auto res = structurallyUniqueBSTs::findUniqueTrees(get<0>(test));
                Assert::IsTrue(res.size() == get<1>(test));
            }
        }

        TEST_METHOD(checkCountStructurallyDiffBSTs)
        {
            vector<tuple<int, int>> tests
            {
                {1, 1},
                {2, 2},
                {3, 5},
                {4, 14},
                {5, 42},
                {6, 132},
                {7, 429},
                {8, 1430},
                {9, 4862},
                {10, 16796},
                {11, 58786},
                {12, 208012},
                {13, 742900},
                {14, 2674440},
                {15, 9694845},
            };

            for (auto test : tests)
            {
                auto res = countOfStructurallyDifferentBSTs::countTrees(get<0>(test));
                Assert::IsTrue(res == get<1>(test));
            }
        }
    };
}