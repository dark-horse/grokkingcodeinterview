#pragma once
#include <vector>
#include <algorithm>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638f7a0a4544c65f117ba260 */
/*
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that
arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices.
Write a function to return the count of such triplets.
*/

class tripletSmallerSum
{
public:
    static int searchTriplets(vector<int>& arr, int target)
    {
        std::sort(arr.begin(), arr.end());
        int res = 0;

        for (int i = 0; i < arr.size() - 2; i++)
        {
            res += searchPair(arr, arr[i], i + 1, arr.size() - 1, target);
        }

        return res;
    }

private:
    static int searchPair(vector<int>& arr, int seed, int lo, int hi, int target)
    {
        int pairCount = 0;
        while (lo < hi)
        {
            int sum = seed + arr[lo] + arr[hi];
            if (sum >= target)
            {
                hi--;
                continue;
            }
            pairCount += hi - lo;
            lo++;
        }

        return pairCount;
    }
};