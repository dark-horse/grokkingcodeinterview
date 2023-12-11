#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63dac2b3bbc58b880202c251 */

class goodPairs
{

public:
    int pairCount(vector<int> nums)
    {
        if (nums.size() <= 1) return 0;

        std::unordered_map<int, int> hash = std::unordered_map<int, int>();
        for (int i = 0; i < nums.size(); i++)
        {
            auto search = hash.find(nums[i]);
            if (search != hash.end())
            {
                hash[nums[i]] = search->second + 1;
            }
            else
            {
                hash[nums[i]] = 1;
            }
        }

        int res = 0;

        for (auto iter = hash.begin(); iter != hash.end(); iter++)
        {
            int count = iter->second;
            res += (count * (count - 1)) / 2;
        }


        return res;
    }
};
