#pragma once

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638fa5205844e928cbf004bf */
/*
** Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.
** Example 1:
** Input: [1, 2, 5, 3, 7, 10, 9, 12]
** Output: 5
** Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted
*/

class minimumWindowSort
{
public:
    static int sort(const vector<int>& arr) {
        
        if (arr.size() == 1) return 0;
        if (arr.size() == 2) return arr[0] <= arr[1] ? 0 : 2;

        int arrSz = arr.size();

        int left = 0;
        while (left < arrSz -1 && arr[left+1] >= arr[left]) left++;

        if (left == arrSz - 1) return 0;   // arr is already sorted.

        int right = arrSz - 1;
        while (right >= 1 && arr[right-1] <= arr[right]) right--;

        // 0...left is sorted and right...arrSz - 1 is sorted
        // left < right because if left >= right then the array is sorted (and we already checked that).

        int min = INT32_MAX, max = INT32_MIN;
        for (int i = left; i <= right; i++)
        {
            min = min > arr[i] ? arr[i] : min;
            max = max < arr[i] ? arr[i] : max;
        }

        // find left such that arr[left] <= min
        // so arr[0..left] <= arr[left+1, right]
        while (left >= 0 && arr[left] > min) left--;

        // find right such that arr[right] >= max
        // so arr[left, right+1] <= arr[right, arrSz-1]
        while (right < arrSz && arr[right] < max) right++;

        return right - left - 1;
    }
};