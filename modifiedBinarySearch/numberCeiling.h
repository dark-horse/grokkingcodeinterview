#pragma once

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639f1fd54e4f288d4a83ab44 */

/*
** Given an array of numbers sorted in an ascending order, find the ceiling of a given number ‘key’.
** The ceiling of the ‘key’ will be the smallest element in the given array greater than or equal to the ‘key’.
**
** Write a function to return the index of the ceiling of the ‘key’. If there isn’t any ceiling return -1.
**
** Example 1:
** Input: [4, 6, 10], key = 6
** Output: 1
** Explanation: The smallest number greater than or equal to '6' is '6' having index '1'.
**
** Example 2:
** Input: [1, 3, 8, 10, 15], key = 12
** Output: 4
** Explanation: The smallest number greater than or equal to '12' is '15' having index '4'.
**
** Example 3:
**
** Input: [4, 6, 10], key = 17
** Output: -1
** Explanation: There is no number greater than or equal to '17' in the given array.
**
** Example 4:
** Input: [4, 6, 10], key = -1
** Output: 0
** Explanation: The smallest number greater than or equal to '-1' is '4' having index '0'.
*/

class numberCeiling
{
public:
    static int searchCeilingOfANumber(const vector<int>& arr, int key)
    {
        int beg = 0, end = arr.size() - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (arr[mid] == key || (arr[mid] > key && (mid == 0 || arr[mid-1] < key))) return mid;

            if (arr[mid] < key)
            {
                beg = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return -1;
    }
};