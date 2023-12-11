#pragma once
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

/*url: https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63d8efe7f8694f3655d60712 */
class containsDuplicates
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        if (nums.size() == 0) return false;

        auto set = std::unordered_set<int>();

        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (set.find(*it) != set.end())
            {
                return true;
            }
            set.insert(*it);
        }

        return false;
    }
};

