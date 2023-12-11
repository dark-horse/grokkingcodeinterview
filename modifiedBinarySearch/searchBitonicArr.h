#pragma once

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639f98b9d239f7cde26ddcaf */

/*
** Given a Bitonic array, find if a given ‘key’ is present in it.
** An array is considered bitonic if it is monotonically increasing and then monotonically decreasing.
** Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].
** Write a function to return the index of the ‘key’.
** If the 'key' appears more than once, return the smaller index. If the ‘key’ is not present, return -1.
**
** Example 1:
** Input: [1, 3, 8, 4, 3], key=4
** Output: 3
**
** Example 2:
** Input: [3, 8, 3, 1], key=8
** Output: 1
**
** Example 3:
** Input: [1, 3, 8, 12], key=12
** Output: 3
**
** Example 4:
** Input: [10, 9, 8], key=10
** Output: 0
*/

class searchBitonicArr
{
public:
    static int search(const vector<int>& arr, int key)
    {
        int chIndex = descIndex(arr);

        if (arr[chIndex] == key) return chIndex;

        if (arr[chIndex] < key)
        {
            return -1;
        }

        int res = searchAsc(arr, 0, chIndex-1, key);
        if (res == -1) return searchDesc(arr, chIndex + 1, arr.size() - 1, key);
    }

    static int searchAsc(const vector<int>& arr, int beg, int end, int key)
    {
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (arr[mid] == key) return mid;
            if (arr[mid] > key) end = mid - 1;
            else beg = mid + 1;
        }

        return -1;
    }

    static int searchDesc(const vector<int>& arr, int beg, int end, int key)
    {
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (arr[mid] == key) return mid;
            if (arr[mid] > key) beg = mid + 1;
            else end = mid - 1; 
        }

        return -1;
    }

    // returns the index where the array switches from ascending to descending.
    static int descIndex(const vector<int>& arr)
    {
        int beg = 0, end = arr.size() - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;

            if (mid > 0 && mid < arr.size() - 1 && arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) return mid;

            if (arr[mid] == arr[beg])
            {
                if (arr[mid] >= arr[end])
                {
                    // the array is constant from beg..to mid and then decreases. Return beg as the point where array starts to be descending.
                    return beg;
                }
                beg = mid + 1;
                continue;
            }

            if (arr[mid] < arr[beg])
            {
                end = mid - 1;
            }
            else
            { 
                beg = mid + 1;
            }
        }

        // did not find the "inflection" point. So the array is increasing.
        return arr.size()-1;
    }
};