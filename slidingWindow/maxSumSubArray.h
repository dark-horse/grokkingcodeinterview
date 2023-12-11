#pragma

using namespace std;

#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/636b1d083b22faa3e89b2458 */
/*
** Given an array of positive numbers and a positive number 'k,' find the maximum sum of any contiguous subarray of size 'k'.
**
** Example 1:
** Input: [2, 1, 5, 1, 3, 2], k=3
** Output: 9
** Explanation: Subarray with maximum sum is [5, 1, 3].
**
** Example 2:
**
** Input: [2, 3, 4, 1, 5], k=2
** Output: 7
** Explanation: Subarray with maximum sum is [3, 4].
*/

class maxSumSubArray
{
public:
    static int findMaxSumSubArray(int k, const vector<int>& arr) {
        int maxSum = 0;
        for (int i = 0; i < k; i++) maxSum += arr[i];
        int currSum = maxSum;
        for (int j = 1; j <= arr.size() - k; j++)
        {
            currSum -= arr[j - 1];
            currSum += arr[j + k - 1];
            maxSum = currSum > maxSum ? currSum : maxSum;
        }
        return maxSum;
    }
};