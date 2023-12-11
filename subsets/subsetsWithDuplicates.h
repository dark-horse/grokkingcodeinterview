#pragma once

using namespace std;

#include <vector>
#include <queue>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639ca98e585e4a974dfff9bf */

/*
** Given a set of numbers that might contain duplicates, find all of its distinct subsets.
**
** Example 1:
** Input: [1, 3, 3]
** Output: [], [1], [3], [1,3], [3,3], [1,3,3]
**
** Example 2:
** Input: [1, 5, 3, 3]
** Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3], [3,3], [1,3,3], [3,3,5], [1,5,3,3]
**
** Example 2:
** Input: [1, 3, 3, 3]
** Output: [], [1], [3], [1,3], [3,3], [1,3,3], [3,3,3], [1,3,3,3]
*/

class subsetsWithDuplicate
{
public:
    static vector<vector<int>> findSubsets(vector<int>& nums)
    {
        vector<vector<int>> subsets;
        subsets.push_back(vector<int>());       // the empty subset
        if (nums.size() == 0) return subsets;
        if (nums.size() == 1) { subsets.push_back(vector<int>(1, nums[0])); return subsets; }
        sort(nums.begin(), nums.end());

        queue<vector<int>> q;
        q.emplace(vector<int>(1, 0));
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1]) continue;
            q.emplace(vector<int>(1, i));
        }

        while (!q.empty())
        {
            auto item = q.front();
            q.pop();
            vector<int> add = vector<int>(item.size());
            for (int i = 0; i < item.size(); i++) add[i] = nums[item[i]];
            subsets.push_back(add);
            if (item[item.size() - 1] + 1 >= nums.size()) continue;
            vector<int> alwaysAddVector = item;
            alwaysAddVector.push_back(item[item.size() - 1] + 1);
            q.emplace(alwaysAddVector);
            for (int i = item[item.size() - 1] + 2; i < nums.size(); i++)
            {
                if (i >  0 && nums[i] == nums[i - 1]) continue;
                vector<int> addVector = item;
                addVector.push_back(i);
                q.emplace(addVector);
            }
        }

        return subsets;
    }
};