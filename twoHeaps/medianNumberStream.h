#pragma once

using namespace std;

#include <queue>
#include <vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639b685c5cda0fa79d72b471 */

/*
** Design a class to calculate the median of a number stream. The class should have the following two methods:
**
** insertNum(int num): stores the number in the class
** findMedian(): returns the median of all numbers inserted in the class
** If the count of numbers inserted in the class is even, the median will be the average of the middle two numbers.
**
** Example 1:
** 1. insertNum(3)
** 2. insertNum(1)
** 3. findMedian() -> output: 2
** 4. insertNum(5)
** 5. findMedian() -> output: 3
** 6. insertNum(4)
** 7. findMedian() -> output: 3.5
*/


class medianNumberStream
{
public:

    medianNumberStream() {}

    /* pre condition: maxPQ.top <= minPQ.top && abs(maxPQ.size() - minPQ.size()) <=1 */
    /* post condition: maxPQ.top <= minPQ.top && abs(maxPQ.size() - minPQ.size()) <=1 */
    void insertNum(int num)
    {
        if (maxPQ.size() == 0 && minPQ.size() == 0)
        {
            maxPQ.push(num);
            return;
        }

        bool popMinPQ = minPQ.size() > 0 && minPQ.top() < num;
        bool popMaxPQ = maxPQ.size() > 0 && maxPQ.top() > num;
        bool insertInMinQ = minPQ.size() == 0 || minPQ.top() < num;

        if (maxPQ.size() != 0 && minPQ.size() != 0)
        {
            if (num < maxPQ.top())
            {
                // num belongs to maxPQ.
                if (maxPQ.size() > minPQ.size())
                {
                    // num belongs to maxPQ, but maxPQ.size() == minPQ.size()+1
                    // maxPQ would grow too much.
                    minPQ.push(maxPQ.top());
                    maxPQ.pop();
                }
                maxPQ.push(num);
            }
            else
            {
                // num belongs to minPQ.
                if (minPQ.size() > maxPQ.size())
                {
                    // minPQ is too big.
                    maxPQ.push(minPQ.top());
                    minPQ.pop();
                }
                minPQ.push(num);
            }
            return;
        }

        if (maxPQ.size() == 0)
        {
            if (num > minPQ.top())
            {
                // num belongs to minPQ, but minPQ is too big
                maxPQ.push(minPQ.top());
                minPQ.pop();
                minPQ.push(num);
            }
            else
            {
                maxPQ.push(num);
            }
            return;
        }

        // minPQ.size() == 0 and maxPQ.size() == 1
        if (num < maxPQ.top())
        {
            // num belongs to maxPQ, but maxPQ is too big.
            minPQ.push(maxPQ.top());
            maxPQ.pop();
            maxPQ.push(num);
        }
        else
        {
            minPQ.push(num);
        }
    }

    double findMedian()
    {
        int streamSz = maxPQ.size() + minPQ.size();
        if (streamSz % 2) return maxPQ.size() > minPQ.size() ? maxPQ.top() : minPQ.top();       // streamSz is odd, so maxPQ.size() cannot be the same as minPQ.size();
        return ((double)maxPQ.top() + (double)minPQ.top()) / 2.0;     // streamSz is even, so maxPQ.size() must equal minPQ.size() (they can differ by at most 1)
    }

private:
    priority_queue<int> maxPQ;  // max priority queue. maxPQ.top() is larger than all items in the queue and maxPQ.top() <= minPQ.top()
    priority_queue<int, vector<int>, greater<int>> minPQ; // min priority queue. minPQ.top() is smaller than all the items in the queue and minPQ.top() >= maxPQ.top()
};