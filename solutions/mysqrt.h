#include<iostream>
#include<intrin.h>
using namespace std;

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63d8fcaae8462840e6bde243 */
class mysqrt
{
public:
    int mySqrt(int x)
    {
        if (x == 0 ) return 0;
        if (x < 4) return 1;
        if (x <= 8) return 2;

        int lo = 3, hi = x / 2;
        while (true)
        {
            int mid = (lo + hi) / 2;
            long long mid_sq = (long long) mid * (long long)mid;
            if (mid_sq > x)
            {
                hi = mid - 1;
                continue;
            }
            long long  mid_p_1_sq = (long long)mid << 1;
            mid_p_1_sq += mid_sq + 1;
            if (mid_sq <= x && mid_p_1_sq > x) return mid;
            lo = mid + 1;
        }
    }

    int fastSqrt(int x)
    {
        if (x == 0) return 0;
        if (x < 4) return 1;
        if (x <= 8) return 2;
        // find the index of the most significant bit
        unsigned long index;
        _BitScanReverse(&index, x);     // only on MSVC
        index++;    // _BitScanReverse returns the 0-based index.
        int lo = 1 << (index-1) / 2;
        int hi = lo << 1;
        while (true)
        {
            int mid = (lo + hi) / 2;
            long long mid_sq = (long long)mid * (long long)mid;
            if (mid_sq > x)
            {
                hi = mid - 1;
                continue;
            }
            long long  mid_p_1_sq = (long long)mid << 1;
            mid_p_1_sq += mid_sq + 1;
            if (mid_sq <= x && mid_p_1_sq > x) return mid;
            lo = mid + 1;
        }
    }
};
