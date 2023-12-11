#pragma once

#include<vector>
#include<unordered_map>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638f9cab70b3327d7a210d9d */

/*
** Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.
** Example 1:
** Input: [4, 1, 2, -1, 1, -3], target=1
** Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
** Explanation: Both the quadruplets add up to the target.
**
** Example 2:
** Input: [2, 0, -1, 1, -2, 2], target=2
** Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
** Explanation: Both the quadruplets add up to the target.
*/

class quadrupleSumToTarget
{
public:
    static vector<vector<int>> searchQuadruplets(vector<int>& arr, int target) {
        // TODO.
        // incomplete solution. This solution lists all the quadruplets, but they are not unique.
        //
        vector<vector<int>> quadruplets;
        if (arr.size() <= 3) return quadruplets;
        if (arr.size() == 4)
        {
            if (arr[0] + arr[1] + arr[2] + arr[3] == target)
            {
                vector<int> add = vector<int>(4);
                add[0] = arr[0]; add[1] = arr[1]; add[2] = arr[2]; add[3] = arr[3];
                quadruplets.push_back(add);
            }
            return quadruplets;
        }

        size_t arrSz = arr.size();

        vector<tuple<int, int, int>> duplets = vector<tuple<int, int, int>>();
        for (int i = 0; i < arrSz; i++)
        {
            for (int j = i + 1; j < arrSz; j++)
            {
                tuple<int, int, int> duplet = tuple<int, int, int>(i, j, arr[i] + arr[j]);
                duplets.push_back(duplet);
            }
        }

        struct
        {
            bool operator() (tuple<int, int, int> a, tuple<int, int, int> b) { return get<2>(a) < get<2>(b); }
        }
        tupleCompare;
        std::sort(duplets.begin(), duplets.end(), tupleCompare);

        int l = 0, r = duplets.size()-1;
        while (l < r)
        {
            auto d_L = duplets[l];
            auto d_R = duplets[r];
            auto sum = get<2>(d_L) + get<2>(d_R);
            if (sum == target)
            {
                if (disjoint(d_L, d_R))
                {
                    vector<int> add = vector<int>(4);
                    add[0] = get<0>(d_L); add[1] = get<1>(d_L); add[2] = get<0>(d_R); add[3] = get<1>(d_R);
                    quadruplets.push_back(add);
                }

                if (r - 1 > l && get<2>(duplets[r - 1]) == get<2>(d_R))
                {
                    auto d_R_1 = duplets[r - 1];
                    if (disjoint(d_L, d_R_1))
                    {
                        vector<int> add = vector<int>(4);
                        add[0] = get<0>(d_L); add[1] = get<1>(d_L); add[2] = get<0>(d_R_1); add[3] = get<1>(d_R_1);
                        quadruplets.push_back(add);
                    }
                }

                if (l + 1 < r && get<2>(duplets[l+1]) == get<2>(d_L))
                {
                    auto d_LPlus1 = duplets[l + 1];
                    if (disjoint(d_LPlus1, d_R))
                    {
                        vector<int> add = vector<int>(4);
                        add[0] = get<0>(d_LPlus1); add[1] = get<1>(d_LPlus1); add[2] = get<0>(d_R); add[3] = get<1>(d_R);
                        quadruplets.push_back(add);
                    }
                }

                l++;
                r--;
            }
            else if (sum > target)
            {
                r--;
            }
            else
            {
                r++;
            }
        }

        return quadruplets;
    }

private:
    static bool disjoint(tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<0>(a) != get<0>(b) && get<0>(a) != get<1>(b) && get<1>(a) != get<0>(b) && get<1>(a) != get<1>(b);
    }
};