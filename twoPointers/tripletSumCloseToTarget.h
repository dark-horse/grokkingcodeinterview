#pragma once
#include <vector>
#include <algorithm>


/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638f7323ae53511bdc364dab */
/*
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet.
If there are more than one such triplet, return the sum of the triplet with the smallest sum.
(for example, if target is 6, and one triplet sums to 4, the other sums to 8, return the one that sums to 4,even though both are equal distance away from 6)
*/

class tripletSumCloseToTarget
{
public:
    static int searchTriplet(vector<int>& arr, int targetSum)
    {
        size_t arrSz = arr.size();
        std::sort(arr.begin(), arr.end());
        int closestBelowTgt = INT32_MIN;
        int closestAboveTgt = INT32_MAX;
        for (int i = 0; i < arrSz; i++)
        {
            searchPair(arr, targetSum, closestBelowTgt, closestAboveTgt, arr[i], i + 1, arrSz - 1);
        }
        return targetSum - closestBelowTgt <= closestAboveTgt - targetSum ? closestBelowTgt : closestAboveTgt;
    }

private:
    static void searchPair(vector<int>& arr, int targetSum, int& closestBelowTgt, int& closestAboveTgt, int seed, int lo, int hi)
    {
        while (lo < hi)
        {
            int sum = seed + arr[lo] + arr[hi];
            if (sum == targetSum)
            {
                closestAboveTgt = sum;
                closestBelowTgt = sum;
                return;
            }

            if (sum > targetSum)
            {
                if (sum < closestAboveTgt)
                {
                    closestAboveTgt = sum;
                }
                hi--;
            }

            if (sum < targetSum)
            {
                if (sum > closestBelowTgt)
                {
                    closestBelowTgt = sum;
                }
                lo++;
            }
        }
    }
};