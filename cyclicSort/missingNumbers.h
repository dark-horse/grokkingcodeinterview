#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6393ada834689e585e94a1b9 */

/*
** We are given an unsorted array containing numbers taken from the range 1 to ‘n’.
** The array can have duplicates, which means some numbers will be missing.
** Find all those missing numbers.
**
** Example 1:
** Input: [2, 3, 1, 8, 2, 3, 5, 1]
** Output: 4, 6, 7
** Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.
**
** Example 2:
** Input: [2, 4, 1, 2]
** Output: 3
**
** Example 3:
** Input: [2, 3, 2, 1]
** Output: 4
*/

class missingNumbers
{
public:
    static vector<int> findNumbers(vector<int>& nums)
    {
        vector<int> missingNumbers;

        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1 && nums[i] != 0)
            {
                int curr = nums[i];
                if (nums[curr - 1] == curr)
                {
                    // curr - 1 != i, this means that nums[curr-1] and nums[i] are duplicates.
                    // make nums[i] = 0 and go to the next integer.
                    // 0 is our sentinel value.
                    nums[i] = 0;
                }
                else
                {
                    swap(nums, i, curr - 1);
                }
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) missingNumbers.push_back(i + 1);
        }

        return missingNumbers;
    }
private:
    static void swap(vector<int>& nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};