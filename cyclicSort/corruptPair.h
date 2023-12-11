#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63948b3326086d487e96e4b3 */

/*
** We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’.
** The array originally contained all the numbers from 1 to ‘n’, but due to a data error,
** one of the numbers got duplicated which also resulted in one number going missing.
** Find both these numbers.
**
** Example 1:
** Input: [3, 1, 2, 5, 2]
** Output: [2, 4]
** Explanation: '2' is duplicated and '4' is missing.
**
** Example 2:
** Input: [3, 1, 2, 3, 6, 4]
** Output: [3, 5]
** Explanation: '3' is duplicated and '5' is missing.
*/

class allDuplicateNumbers
{
public:
    static vector<int> findNumbers(vector<int>& nums) {
        vector<int> pair;

        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1 && nums[i] != 0)
            {
                int curr = nums[i];
                if (nums[curr - 1] == curr)
                {
                    pair.push_back(curr);
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
            if (nums[i] == 0)
            {
                pair.push_back(i + 1);
                break;
            }
        }

        return pair;
    }

private:
    static void swap(vector<int>& nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};