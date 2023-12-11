#pragma once

using namespace std;

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639f9a0cd239f7cde26dde2b */

/*
** Given an array of numbers which is sorted in ascending order and also rotated by some arbitrary number, find if a given ‘key’ is present in it.
** Write a function to return the index of the ‘key’ in the rotated array.
** If the ‘key’ is not present, return -1. You can assume that the given array does not have any duplicates.
**
** Example 1:
** Input: [10, 15, 1, 3, 8], key = 15
** Output: 1
** Explanation: '15' is present in the array at index '1'.
**
** Example 2:
** Input: [4, 5, 7, 9, 10, -1, 2], key = 10
** Output: 4
** Explanation: '10' is present in the array at index '4'.
*/

class searchRotatedArray
{
public:
    static int search(const vector<int>& arr, int key)
    {
        int rotationIndex = peakIndex(arr);

        if (key > arr[rotationIndex]) return -1;
        if (rotationIndex == arr.size() - 1 && key < arr[0]) return -1;
        if (rotationIndex < arr.size() - 1 && key < arr[rotationIndex + 1]) return -1;

        int beg = 0, end = arr.size() - 1;

        if (key == arr[rotationIndex]) return rotationIndex;

        if (key < arr[0])
        {
            // key is from rotationIndex to the end of the array.
            return findKey(arr, rotationIndex+1, arr.size() - 1, key);
        }

        return findKey(arr, 0, rotationIndex-1, key);
    }

private:
    static int findKey(const vector<int>& arr, int beg, int end, int key)
    {
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (arr[mid] == key) return mid;
            if (arr[mid] > key)
            {
                end = mid - 1;
            }
            else
            {
                beg = mid + 1;
            }
        }

        return -1;
    }

    static int peakIndex(const vector<int>& arr)
    {
        if (arr[arr.size() - 1] >= arr[0]) return arr.size() - 1;    // no rotation base case

        int beg = 0, end = arr.size() - 1;

        while (beg <= end)
        {
            int mid = (beg + end) / 2;

            if (mid < arr.size() - 1 && arr[mid] > arr[mid + 1]) return mid;

            if (arr[mid] >= arr[0])
            {
                beg = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return arr.size() - 1;
    }
};