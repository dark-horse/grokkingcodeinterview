#pragma once

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639f967aba1e473bb5b8d519 */

/*
** Given an array of numbers sorted in ascending order, find the element in the array that has the minimum difference with the given ‘key’.
**
** Example 1:
** Input: [4, 6, 10], key = 7
** Output: 6
** Explanation: The difference between the key '7' and '6' is minimum than any other number in the array
**
** Example 2:
** Input: [4, 6, 10], key = 4
** Output: 4
**
** Example 3:
** Input: [1, 3, 8, 10, 15], key = 12
** Output: 10
**
** Example 4:
** Input: [4, 6, 10], key = 17
** Output: 10

** Additional specifications: by difference it means distance (or absolute value)
** here is an example
** Input: [4, 6, 10], key = 9
** Output: 10 (not 6).
** Another specification: when at equal distance between two different integers, pick the smallest integer
** 
** Example:
** Input: [4, 6, 10], key = 5
** Output: 4
*/


class minDiff
{
public:
    static int searchMinDiffElement(const vector<int>& arr, int key)
    {
        // some base cases
        if (key <= arr[0]) return arr[0];
        if (key >= arr[arr.size() - 1]) return arr[arr.size() - 1];

        int res = -1, minDiff = INT32_MAX, resIndex = INT32_MAX;

        int beg = 0, end = arr.size() - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (arr[mid] == key) return arr[mid];
            int diff = abs(arr[mid] - key);

            if ((minDiff == diff && mid <= resIndex) || minDiff > diff)     // when key is equally distant from two different points, picks the smallest one.
            {
                minDiff = diff;
                res = arr[mid];
                resIndex = mid;
            }

            if (arr[mid] < key)
            {
                beg = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return res;
    }
};