#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639ddbfd1558f46adcdc699c */

/*
** Given a number ‘n’, write a function to return the count of structurally unique Binary Search Trees (BST) that can store values 1 to ‘n’.
**
** Example 1:
** Input: 2
** Output: 2
** Explanation: As we saw in the previous problem, there are 2 unique BSTs storing numbers from 1-2.
**
** Example 2:
** Input: 3
** Output: 5
** Explanation: There will be 5 unique BSTs that can store numbers from 1 to 3.
*/

class countOfStructurallyDifferentBSTs
{
public:
    static int countTrees(int n)
    {
        if (n == 0) return 1;
        if (n == 1 || n == 2) return n;

        //using the mnemonic cuts down test run time from 33 ms to less than 1 ms.
        vector<vector<int>> tbl;

        for (int i = 0; i < n; i++)
        {
            tbl.push_back(vector<int>(n, -1));  // sentinel value will be -1, because the count can never be negative.
            tbl[i][i] = 1;
            if (i >= 1) tbl[i - 1][i] = 2;
        }
        return countTreesRecursive(1, n, tbl);
    }

private:
    static int countTreesRecursive(int beg, int end, vector<vector<int>>& tbl)
    {
        if (tbl[beg - 1][end - 1] != -1) return tbl[beg - 1][end - 1];      // -1 because vector indices are 0-based.
        int res = 0;
        if (beg > end) return 0;

        /*
        ** these bases cases have been updated in the tbl.
        if (beg == end) return 1;
        if (beg == end - 1) return 2;
        */

        res += countTreesRecursive(beg + 1, end, tbl) + countTreesRecursive(beg, end - 1, tbl);

        for (int i = beg + 1; i <= end - 1; i++)
        {
            int left = countTreesRecursive(beg, i - 1, tbl);
            int right = countTreesRecursive(i + 1, end, tbl);
            res += left * right;
        }

        tbl[beg - 1][end - 1] = res;

        return res;
    }
};