#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6393b0a334689e585e94a29a */

/*
** We are given an unsorted array containing n numbers taken from the range 1 to n.
** The array has some numbers appearing twice, find all these duplicate numbers using constant space.
**
** Example 1:
** Input: [3, 4, 4, 5, 5]
** Output: [4, 5]
**
** Example 2:
** Input: [5, 4, 7, 2, 3, 5, 3]
** Output: [3, 5]
*/

class allDuplicateNumbers
{
public:
    static vector<int> findNumbers(vector<int>& nums) {
        vector<int> duplicateNumbers;

        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1 && nums[i] != 0)
            {
                int curr = nums[i];
                if (nums[curr - 1] == curr)
                {
                    duplicateNumbers.push_back(curr);
                    nums[i] = 0;
                }
                else
                {
                    swap(nums, i, curr - 1);
                }
            }
        }

        return duplicateNumbers;
    }

private:
    static void swap(vector<int>& nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};