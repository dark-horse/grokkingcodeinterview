#pragma once
#include <vector>

using namespace std;

/*url: https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638e39bd1756319ef156bebc */
/* Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order. */
class squaringSortedArray
{
public:
    static vector<int> makeSquares(const vector<int>& arr)
    {
        size_t arrSz = arr.size();
        vector<int> res(arrSz);
        if (arrSz == 0) return res;

        // some base cases first:
        // 1. all numbers are negative 
        if (arr[arrSz - 1] <= 0)
        {
            for (int i = 0; i < arrSz; i++)
            {
                res[i] = arr[arrSz - i - 1] * arr[arrSz - i - 1];
            }
            return res;
        }
        // 2. all numbers are positive
        if (arr[0] >= 0)
        {
            for (int i = 0; i < arrSz; i++)
            {
                res[i] = arr[i] * arr[i];
            }
            return res;
        }

        // find the first non-negative number via binary search
        int lo = 0, hi = arrSz - 1, nonNegIndex = 0;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (arr[mid] > 0)
            {
                if (arr[mid - 1] <= 0)
                {
                    nonNegIndex = mid;
                    break;
                }
                hi = mid - 1;
            }
            else if (arr[mid] < 0)
            {
                if (arr[mid + 1] >= 0)
                {
                    nonNegIndex = mid + 1;
                    break;
                }
                lo = mid + 1;
            }
            else
            {
                // arr[mid] == 0; 0 is non-negative
                nonNegIndex = mid;
                break;
            }
        }

        int negIndex = nonNegIndex - 1;
        for (int i = 0; i < arrSz; i ++)
        {
            if (negIndex < 0)
            {
                res[i] = arr[nonNegIndex] * arr[nonNegIndex];
                nonNegIndex++;
                continue;
            }
            if (nonNegIndex >= arrSz)
            {
                res[i] = arr[negIndex] * arr[negIndex];
                negIndex--;
                continue;
            }
            int negSq = arr[negIndex] * arr[negIndex];
            int posSq = arr[nonNegIndex] * arr[nonNegIndex];
            if (negSq < posSq)
            {
                res[i] = negSq;
                negIndex--;
            }
            else
            {
                res[i] = posSq;
                nonNegIndex++;
            }

        }

        return res;
    }
};

