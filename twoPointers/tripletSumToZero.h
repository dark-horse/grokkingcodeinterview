#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638f6ff2ae53511bdc36490d */
/* Given an array of unsorted numbers, find all unique triplets in it that add up to zero. */

class tripletSumToZero
{
public:
    static vector<vector<int>> searchTriplets(vector<int>& arr) {
        vector<vector<int>> triplets;

        // this solution does not use two pointers....
        auto negativeNumbers = unordered_map<int,int>();
        size_t arrSz = arr.size();
        for (int i = 0; i < arrSz; i++)
        {
            negativeNumbers[0 - arr[i]] = i;
        }

        for (int i = 0; i < arrSz; i++)
        {
            for (int j = i + 1; j < arrSz; j++)
            {
                auto e = negativeNumbers.find(arr[i] + arr[j]);
                if (e == negativeNumbers.end()) continue;
                if (e->second != i && e->second != j)
                {
                    auto add = vector<int>(3, -1);
                    add[0] = arr[i];
                    add[1] = arr[j];
                    add[2] = 0 - arr[i] - arr[j];
                    std::sort(add.begin(), add.end());
                    bool found = false;
                    for (int k = 0; k < triplets.size(); k++)
                    {
                        if (triplets[k][0] == add[0] && triplets[k][1] == add[1] && triplets[k][2] == add[2])
                        {
                            found = true;
                            break;
                        }
                    }
                    if (!found) triplets.push_back(add);
                }
            }
        }

        return triplets;
    }
};