#pragma once

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/636b1d083b22faa3e89b2478 */

/*
** Given an array of positive integers and a number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to 'S'. Return 0 if no such subarray exists.
** Example 1:
** Input: [2, 1, 5, 2, 3, 2], S=7
** Output: 2
** Explanation: The smallest subarray with a sum greater than or equal to '7' is [5, 2].
**
** Example 2:
** Input: [2, 1, 5, 2, 8], S=7
** Output: 1
** Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
**
** Example 3:
** Input: [3, 4, 1, 1, 6], S=8
** Output: 3
** Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] or [1, 1, 6].
*/

class smallestSumWithGreatedSum
{
public:
    static int findMinSubArray(int S, const vector<int>& arr) {
        // some base cases.
        if (arr.size() == 0) return 0;
        if (S <= 0) return 1; // any number in the array would work. And that is a sub-array with length 1.

        if (arr.size() == 1) return arr[0] >= S ? 1 : 0;

        int sum = 0, l = 0, r = 0, len = INT32_MAX;
        while (r < arr.size())
        {
            sum += arr[r];
            while (r < arr.size() - 1 && sum < S)
            {
                r++;
                sum += arr[r];
            }

            while (l <= r && sum >= S)
            {
                int newLen = r - l + 1;
                len = len > newLen ? newLen : len;
                sum -= arr[l];
                l++;
            }
            r++;
        }

        return len != INT32_MAX ? len : 0;
    }
};