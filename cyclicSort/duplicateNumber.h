#pragma once

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/6393aee5ba7c985340679287 */

/*
** We are given an unsorted array containing n+1 numbers taken from the range 1 to n.
** The array has only one duplicate but it can be repeated multiple times.
** Find that duplicate number without using any extra space.
** You are, however, allowed to modify the input array.
**
** Example 1:
** Input: [1, 4, 4, 3, 2]
** Output: 4
**
** Example 2:
** Input: [2, 1, 3, 3, 5, 4]
** Output: 3
**
** Example 3:
** Input: [2, 4, 1, 4, 4]
** Output: 4
*/

class duplicateNumber
{
public:
    static int findNumber(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1)
            {
                int curr = nums[i];
                if (nums[curr - 1] == curr) return curr;
                swap(nums, i, curr - 1);
            }
        }
    }

private:
    static void swap(vector<int>& nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};