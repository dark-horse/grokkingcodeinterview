#pragma once

using namespace std;

#include <vector>
#include <queue>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639c8fe6165a22967d308303 */

/*
** Given an array of numbers and a number ‘k’, find the median of all the ‘k’ sized sub-arrays (or windows) of the array.
**
** Example 1:
** Input: nums=[1, 2, -1, 3, 5], k = 2
** Output: [1.5, 0.5, 1.0, 4.0]
** Explanation: Let's consider all windows of size ‘2’:
** [1, 2, -1, 3, 5] -> median is 1.5
** [1, 2, -1, 3, 5] -> median is 0.5
** [1, 2, -1, 3, 5] -> median is 1.0
** [1, 2, -1, 3, 5] -> median is 4.0
**
** Example 2:
** Input: nums=[1, 2, -1, 3, 5], k = 3
** Output: [1.0, 2.0, 3.0]
** Explanation: Let's consider all windows of size ‘3’:
** [1, 2, -1, 3, 5] -> median is 1.0
** [1, 2, -1, 3, 5] -> median is 2.0
** [1, 2, -1, 3, 5] -> median is 3.0
*/

class slidingWindowMedian
{
public:
    static vector<double> findSlidingWindowMedian(const vector<int>& nums, int k)
    {
        vector<double> result(nums.size() - k + 1);
        if (k == 1)
        {
            for (int i = 0; i < nums.size(); i++) result[i] = nums[i];
            return result;
        }

        if (k == 2)
        {
            for (int i = 1; i < nums.size(); i++) result[i-1] = ((double)nums[i - 1] + (double)nums[i]) / 2;
            return result;
        }

        // add the first two items to the queues
        priority_queue<int> maxPQ;
        priority_queue<int, vector<int>, greater<int>> minPQ;
        if (nums[0] < nums[1])
        {
            maxPQ.push(nums[0]);
            minPQ.push(nums[1]);
        }
        else
        {
            maxPQ.push(nums[1]);
            minPQ.push(nums[0]);
        }

        // build the queues with the first k items in the array
        for (int i = 2; i < k; i++)
        {
            addNumberToQueues(nums[i], minPQ, maxPQ);
        }

        for (int i = 0; i < result.size(); i++)
        {
            if (k % 2) result[i] = minPQ.size() > maxPQ.size() ? minPQ.top() : maxPQ.top();
            else result[i] = ((double)minPQ.top() + (double)maxPQ.top()) / 2;

            if (i < result.size() - 1) addremoveNumberFromQueues(nums[i + k], nums[i], minPQ, maxPQ);
        }

        return result;
    }

private:
    /* pre condition: all numbers in maxPQ are smaller than maxPQ.top() and all numbers in minPQ are larger than minPQ.top() and minPQ.top() >= maxPQ.top() and abs(minPQ.size() - maxPQ.size()) <= 1*/
    /* post condition: same as pre.*/
    static void addNumberToQueues(int num, priority_queue<int, vector<int>, greater<int>>& minPQ, priority_queue<int>& maxPQ)
    {
        if (num < maxPQ.top())
        {
            // num belongs to maxPQ
            if (maxPQ.size() > minPQ.size())
            {
                minPQ.push(maxPQ.top());
                maxPQ.pop();
            }
            maxPQ.push(num);
        }
        else
        {
            // num belongs to minPQ
            if (minPQ.size() > maxPQ.size())
            {
                maxPQ.push(minPQ.top());
                minPQ.pop();
            }
            minPQ.push(num);
        }
    }

    static void addremoveNumberFromQueues(int numToAdd, int numToRemove, priority_queue<int, vector<int>, greater<int>>& minPQ, priority_queue<int>& maxPQ)
    {
        if (numToAdd < maxPQ.top()) maxPQ.push(numToAdd);
        else minPQ.push(numToAdd);

        if (numToRemove <= maxPQ.top())
        {
            // how do you remove an item from a priority queue.....
            vector<int> remainders;
            while (maxPQ.top() != numToRemove)
            {
                remainders.push_back(maxPQ.top());
                maxPQ.pop();
            }
            maxPQ.pop();
            for (int i = 0; i < remainders.size(); i++) maxPQ.push(remainders[i]);
        }
        else
        {
            vector<int> remainders;
            while (minPQ.top() != numToRemove)
            {
                remainders.push_back(minPQ.top());
                minPQ.pop();
            }

            minPQ.pop();
            for (int i = 0; i < remainders.size(); i++) minPQ.push(remainders[i]);
        }

        while (minPQ.size() > maxPQ.size() + 1)
        {
            maxPQ.push(minPQ.top());
            minPQ.pop();
        }

        while (maxPQ.size() > minPQ.size() + 1)
        {
            minPQ.push(maxPQ.top());
            maxPQ.pop();
        }
    }
};