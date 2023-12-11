#pragma once

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639f27ef7ae2ac6893f42b83 */

/*
** Given an array of numbers sorted in ascending order, find the range of a given number ‘key’.
** The range of the ‘key’ will be the first and last position of the ‘key’ in the array.
** Write a function to return the range of the ‘key’. If the ‘key’ is not present return [-1, -1].
**
** Example 1:
** Input: [4, 6, 6, 6, 9], key = 6
** Output: [1, 3]
**
** Example 2:
** Input: [1, 3, 8, 10, 15], key = 10
** Output: [3, 3]
**
** Example 3:
** Input: [1, 3, 8, 10, 15], key = 12
** Output: [-1, -1]
*/

class numberRange
{
public:
    static vector<int> findRange(const vector<int>& arr, int key)
    {
        int keyIndex = -1, beg = 0, end = arr.size() - 1;

        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (arr[mid] == key)
            {
                keyIndex = mid;
                break;
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

        if (keyIndex == -1) return vector<int>(2, -1);

        // binary search to see the earliest index where arr[index] == key;
        int low = keyIndex;
        beg = 0;
        end = keyIndex - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (arr[mid] == key && (mid == 0 || arr[mid - 1] < key))
            {
                low = mid;
                break;
            }

            if (arr[mid] < key) beg = mid + 1;
            else end = mid - 1;
        }

        // binary search to see the last index where arr[index] == key;
        int hi = keyIndex;
        beg = keyIndex + 1;
        end = arr.size() - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (arr[mid] == key && (mid == arr.size()- 1 || (mid < arr.size() - 1 && arr[mid + 1] > key)))
            {
                hi = mid;
                break;
            }

            if (arr[mid] > key) end = mid - 1;
            else beg = mid + 1;
        }

        vector<int> res = vector<int>(2);
        res[0] = low;
        res[1] = hi;
        return res;
    }
};