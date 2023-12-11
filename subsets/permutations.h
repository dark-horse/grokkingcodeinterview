#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639cae5754a43e1fc3c40cb6 */

/*
** Given a set of distinct numbers, find all of its permutations.
** Permutation is defined as the re-arranging of the elements of the set.
**
** For example, {1, 2, 3} has the following six permutations:
** {1, 2, 3} {1, 3, 2} {2, 1, 3} {2, 3, 1} {3, 1, 2} {3, 2, 1} If a set has ‘n’ distinct elements it will have n!n! permutations.
**
** Example 1:
** Input: [1,3,5]
** Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]
*/

class permutations
{
public:
    static vector<vector<int>> findPermutations(const vector<int>& nums)
    {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        if (nums.size() == 1) { result.push_back(nums); return result; }
        vector<int> workingVec(nums);
        findPermutationsRecursive(result, 0, nums.size() - 1, workingVec);
        return result;
    }

private:
    static void findPermutationsRecursive(vector<vector<int>>& res, int beg, int end, vector<int>& workingVec)
    {
        if (beg == end - 1)
        {
            // base case
            res.push_back(workingVec);
            swap(workingVec, beg, end);
            res.push_back(workingVec);
            swap(workingVec, beg, end);
            return;
        }

        for (int i = beg; i <= end; i++)
        {
            swap(workingVec, beg, i);
            findPermutationsRecursive(res, beg+1, end, workingVec);
            swap(workingVec, beg, i);
        }
    }

    static void swap(vector<int>& arr, int a, int b)
    {
        if (a == b) return;
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
};