#pragma once
#include <vector>

using namespace std;

/*url: https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638ca0aa5b41522e8a2e3395 */
/* Given an array of numbers sorted in ascending order and a target sum, find a pair in the array whose sum is equal to the given target. */
class pairWithTarget
{
public:
    static vector<int> search(const vector<int>& arr, int targetSum)
    {
        vector<int> res(2,-1);  // the default result - no match.
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi)
        {
            int sum = arr[lo] + arr[hi];
            if (sum == targetSum)
            {
                res[0] =lo;
                res[1] = hi;
                return res;
            }
            if (sum < targetSum)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }

        return res;
    }
};

