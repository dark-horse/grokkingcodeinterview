#pragma once

using namespace std;

#include<vector>
#include<queue>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639ca6d8585e4a974dfff649 */

/*
** Given a set with distinct elements, find all of its distinct subsets.
**
** Example 1:
** Input: [1, 3]
** Output: [], [1], [3], [1,3]
**
** Example 2:
** Input: [1, 5, 3]
** Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]
*/

class subsets
{
public:
    static vector<vector<int>> findSubsets(const vector<int>& nums)
    {
        vector<vector<int>> subsets;
        subsets.push_back(vector<int>());       // the empty subset
        queue<vector<int>> q;
        for (int i = 0; i < nums.size(); i++)
        {
            q.emplace(vector<int>(1, i));
        }

        while (!q.empty())
        {
            auto item = q.front();
            q.pop();
            vector<int> add = vector<int>(item.size());
            for (int i = 0; i < item.size(); i++) add[i] = nums[item[i]];
            subsets.push_back(add);
            for (int i = item[item.size() - 1] + 1; i < nums.size(); i++)
            {
                vector<int> addVector = item;
                addVector.push_back(i);
                q.emplace(addVector);
            }
        }

        return subsets;
    }
};