#pragma once

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638f976d20f87893374e4e6b */
/*
Given an array with positive numbers and a positive target number, find all of its contiguous subarrays whose product is less than the target number.

Example 1:

Input: [2, 5, 3, 10], target=30
Output: [2], [5], [2, 5], [3], [5, 3], [10]
Explanation: There are six contiguous subarrays whose product is less than the target.
*/

class subarraysProductLessThanTarget
{
public:
    static vector<vector<int>> findSubarrays(const vector<int>& arr, int target)
    {
        vector<vector<int>> result;

        for (int beg = 0; beg < arr.size(); beg++)
        {
            bool regionExists = false;
            int end;
            findMaxInterval(arr, beg, end, regionExists, target);
            if (regionExists)
            {
                // the product of the numbers in the interval [beg...end] is less than target.
                // this means the product of any numbers in this interval is also less than target (because all numbers are positive...)
                // so add all the intervals that start with beg
                // the intervals starting with beg+1, or beg+2 will be done at the following iteration.
                vector<int> intervals = vector<int>(1, arr[beg]);
                result.push_back(intervals);
                for (int i = beg + 1; i <= end; i++)
                {
                    intervals.push_back(arr[i]);
                    result.push_back(intervals);
                }
            }
        }

        return result;
    }

    static vector<vector<int>> findSubarraysSlidingWindowWrong(const vector<int>& arr, int target)
    {
        vector<vector<int>> result;

        int beg = 0, end = 0;
        long long prod = arr[0];
        while (beg < arr.size())
        {
            prod = beg >= end ? arr[beg] : prod;
            end = end >= beg ? end : beg;
            while (prod < (long long)target && end < arr.size())
            {
                end++;
                prod *= arr[end];
            }

            vector<int> add = vector<int>();

            for (int i = beg; i < end; i++)
            {
                add.push_back(arr[i]);
                result.push_back(add);
            }
            prod = prod / arr[beg];
            beg++;
        }

        return result;
    }

    static vector<vector<int>> findSubarraysSlidingWindow(const vector<int>& arr, int target)
    {
        vector<vector<int>> result;
        if (arr.size() == 0) return result;

        int beg = 0, end = 0;
        long long prod = (long long) arr[0];
        while (end < arr.size())
        {
            if (prod < (long long)target)
            {
                vector<int> add;
                for (int i = end; i >= beg; i--)
                {
                    add.insert(add.begin(),arr[i]);
                    result.push_back(add);
                }
                end++;
                prod = end < arr.size() ? prod * arr[end] : prod;
                continue;
            }

            while (prod >= (long long)target && beg <= end)
            {
                prod = prod / arr[beg];
                beg++;
            }

            if (beg > end)
            {
                end++;
                prod = end < arr.size() ? prod * arr[end] : prod;
            }
        }

        return result;
    }

private:
    // finds the maximum interval starting at beg such that the product of all numbers in that interval is less than target
    static void findMaxInterval(const vector<int>& arr, int& beg, int& end, bool& regionExists, int target)
    {
        regionExists = false;
        long long longTgt = (long long)target;
        for (; beg < arr.size(); beg++)
        {
            long long prod = (long long) arr[beg];
            regionExists = prod < longTgt;
            end = beg;

            while (prod < longTgt && end + 1 < arr.size())
            {
                regionExists = true;
                end++;
                prod = prod * (long long) arr[end];
            }
            end -= prod >= longTgt; // decrement end only if we exited the loop because prod >= longTgt

            if (regionExists) break;
        }
    }
};