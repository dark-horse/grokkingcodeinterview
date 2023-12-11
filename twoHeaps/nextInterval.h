#pragma once

using namespace std;

#include<vector>
#include<queue>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/639ca31ddf76bf2533026e64 */

/*
** Given an array of intervals, find the next interval of each interval.
** In a list of intervals, for an interval ‘i’ its next interval ‘j’ will have the smallest ‘start’ greater than or equal to the ‘end’ of ‘i’.
**
** Write a function to return an array containing indices of the next interval of each input interval.
** If there is no next interval of a given interval, return -1.
** It is given that none of the intervals have the same start point.
**
** Example 1:
** Input: Intervals [[2,3], [3,4], [5,6]]
** Output: [1, 2, -1]
** Explanation: The next interval of [2,3] is [3,4] having index ‘1’. Similarly, the next interval of [3,4] is [5,6] having index ‘2’. There is no next interval for [5,6] hence we have ‘-1’.
**
** Example 2:
** Input: Intervals [[3,4], [1,5], [4,6]]
** Output: [2, -1, -1]
** Explanation: The next interval of [3,4] is [4,6] which has index ‘2’. There is no next interval for [1,5] and [4,6].
*/

class nextInterval
{
public:
    class Interval {
    public:
        int start = 0;
        int end = 0;

        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }

        // the magic formula to be able to construct vector<Interval>
        Interval() {}

        // the magic formula (magic function signature) to use for equality test when comparing vectors.
        bool operator==(const Interval& a) const { return this->start == a.start && this->end == a.end; }
    };

    static vector<Interval> constructIntervals(const vector<vector<int>> input)
    {
        vector<Interval> res;
        for (int i = 0; i < input.size(); i++)
        {
            res.push_back(Interval(input[i][0], input[i][1]));
        }

        return res;
    }

    static vector<int> findNextInterval(const vector<Interval>& intervals)
    {
        int n = intervals.size();
        vector<int> result(n, -1);

        priority_queue<intervalAndIndex, vector<intervalAndIndex>, intervalAndIndex::SmallerByIntervalEnd>  minIntervalEnd;
        priority_queue<intervalAndIndex, vector<intervalAndIndex>, intervalAndIndex::SmallerByIntervalStart>  minIntervalStart;

        for (int i = 0; i < intervals.size(); i++)
        {
            minIntervalEnd.push(intervalAndIndex(intervals[i].start, intervals[i].end, i));
            minIntervalStart.push(intervalAndIndex(intervals[i].start, intervals[i].end, i));
        }

        while (!minIntervalEnd.empty() && !minIntervalStart.empty())
        {
            auto interval = minIntervalEnd.top();
            minIntervalEnd.pop();
            while (!minIntervalStart.empty() && minIntervalStart.top().interval.start < interval.interval.end) minIntervalStart.pop();
            if (minIntervalStart.empty()) break;
            result[interval.index] = minIntervalStart.top().index;
        }

        return result;
    }

private:
    class intervalAndIndex
    {
    public:
        nextInterval::Interval interval = nextInterval::Interval(0, 0);
        int index;
        intervalAndIndex(int start, int end, int index) : interval(start, end), index(index) {}

        struct SmallerByIntervalEnd
        {
            bool operator()(const intervalAndIndex& lhs, const intervalAndIndex& rhs) const
            {
                return lhs.interval.end > rhs.interval.end;
            }
        };

        struct SmallerByIntervalStart
        {
            bool operator()(const intervalAndIndex& lhs, const intervalAndIndex& rhs) const
            {
                return lhs.interval.start > rhs.interval.start;
            }
        };
    };
};