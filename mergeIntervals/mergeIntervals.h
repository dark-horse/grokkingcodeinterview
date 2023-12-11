#pragma once

using namespace std;

#include <vector>
#include <algorithm>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/63923e6de4cb724ea719007a */
/*
** Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.
**
** Example 1:
** Intervals: [[1,4], [2,5], [7,9]]
** Output: [[1,5], [7,9]]
** Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into one [1,5].
**
** Example 2:
** Intervals: [[6,7], [2,4], [5,9]]
** Output: [[2,4], [5,9]]
** Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into one [5,9].
**
** Example 3:
** Intervals: [[1,4], [2,6], [3,5]]
** Output: [[1,6]]
** Explanation: Since all the given intervals overlap, we merged them into one.
*/

class mergeIntervals
{
public:
    class Interval
    {
    public:
      int start = 0;
      int end = 0;

      Interval(int start, int end) {
        this->start = start;
        this->end = end;
      }

      // the magic formula (magic function signature) to use for equality test when comparing vectors.
      bool operator==(const Interval& a) const { return this->start == a.start && this->end == a.end; }
    };

    static vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> mergedIntervals;
        if (intervals.size() <= 1) return intervals;

        struct
        {
            bool operator() (Interval a, Interval b) { return a.start < b.start || (a.start == b.start && a.end < b.end); }
        }
        intervalCompare;

        std::sort(intervals.begin(), intervals.end(), intervalCompare);

        int l = 0, r = 0, rBoundary = intervals[0].end;

        while (r < intervals.size())
        {
            while (r < intervals.size() && intervals[r].start <= rBoundary)
            {
                rBoundary = rBoundary > intervals[r].end ? rBoundary : intervals[r].end;
                r++;
            }

            Interval newInterval = Interval(intervals[l].start, rBoundary);
            mergedIntervals.push_back(newInterval);

            l = r;

            if (r < intervals.size()) rBoundary = intervals[r].end;
        }

        return mergedIntervals;
    }
};