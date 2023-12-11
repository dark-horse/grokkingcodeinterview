#pragma once

using namespace std;

#include <unordered_set>
#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63948df2f34bef51e103b6d7 */
/*
** Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.
**
** Example 1:
** Input: [3, -1, 4, 5, 5], k=3
** Output: [1, 2, 6]
** Explanation: The smallest missing positive numbers are 1, 2 and 6.
**
** Example 2:
** Input: [2, 3, 4], k=3
** Output: [1, 5, 6]
** Explanation: The smallest missing positive numbers are 1, 5 and 6.
**
** Example 3:
** Input: [-2, -3, 4], k=2
** Output: [1, 2]
** Explanation: The smallest missing positive numbers are 1 and 2.
*/

class kMissingIntegers
{
public:
    static vector<int> findNumbers(vector<int>& nums, int k) {
        vector<int> missingNumbers;
        unordered_set<int> largerThanN = unordered_set<int>();
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1 && nums[i] != 0)
            {
                int curr = nums[i];
                if (curr > nums.size() || curr < 0 || nums[curr - 1] == curr)
                {
                    if (curr > nums.size()) largerThanN.insert(curr);
                    nums[i] = 0;
                }
                else
                {
                    swap(nums, i, curr - 1);
                }
            }
        }

        for (int i = 0; i < nums.size() && k > 0; i++)
        {
            if (nums[i] == 0)
            {
                missingNumbers.push_back(i + 1);
                k--;
            }
        }

        for (int seed = nums.size()+1; k > 0; seed++)
        {
            if (largerThanN.find(seed) != largerThanN.end()) continue;
            missingNumbers.push_back(seed);
            k--;
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